#include <algorithm>
#include <complex>
#include "fft_20180208.h"
#include "netxpto_20180118.h"
#include "snr_estimator_20180227.h"
#include <typeinfo>
#include <stdexcept>

//// Currently estimating SNR only for real valued electrical signals.
//// Does not work for SNR< 10dB. Results also dubious for SNR>35;
//// Needs improvement.



void SNREstimator::initialize(void) {
	firstTime = false;

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
	if (numberOfInputSignals == 2 && numberOfOutputSignals == 2) {
		outputSignals[1]->setSymbolPeriod(inputSignals[1]->getSymbolPeriod());
		outputSignals[1]->setSamplingPeriod(inputSignals[1]->getSamplingPeriod());
		outputSignals[1]->setFirstValueToBeSaved(inputSignals[1]->getFirstValueToBeSaved());
	}
}

bool SNREstimator::runBlock(void) {

	double inValueI;
	double inValueQ;
	double samplingPeriod = inputSignals[0]->getSamplingPeriod();
	double symbolPeriod = inputSignals[0]->getSymbolPeriod();
	int sps = inputSignals[0]->getSamplesPerSymbol();
	vector<double> segment;
	vector <double> im(segmentSize);
	vector <complex<double>> segmentComplex(segmentSize);
	vector <complex<double>> fourierTransformed;
	double noisePower = 0;
	double signalPower = 0;
	double SNR = 0;
	double stdSNR = 0;
	double LowerBound;
	double UpperBound;
	complex<double> inValue;

	// If its the first pass, calculate z for finding the confidence interval.
	// Also, calculate the window to be used and the vector of frequencies.
	if (firstPass) {
		firstPass = false;
		double x1 = -2;
		double x2 = 2;
		double x3 = x2 - (erf(x2 / sqrt(2)) + 1 - alpha)*(x2 - x1) / (erf(x2 / sqrt(2)) - erf(x1 / sqrt(2)));
		double exactness = 1e-15;
		while (abs(erf(x3 / sqrt(2)) + 1 - alpha) > exactness)
		{
			x3 = x2 - (erf(x2 / sqrt(2)) + 1 - alpha)*(x2 - x1) / (erf(x2 / sqrt(2)) - erf(x1 / sqrt(2)));
			x1 = x2;
			x2 = x3;
		}
		z = -x3;

		window = getWindow(windowType, segmentSize);
		
		U = 0;	// Window normalization constant
		for (unsigned int i = 0; i < window.size(); i++) {
			U += pow(window[i], 2);
		}
		U = U / window.size();
		
		for (int i = 0; i < segmentSize; i++) {
			frequencies.insert(frequencies.end(), ((1 + i - segmentSize / 2) * 1 / samplingPeriod)/segmentSize);
		}
	}
	
	int ready;
	int space;

	if (numberOfInputSignals == 2 && numberOfOutputSignals == 2) {
		ready = min(inputSignals[0]->ready(), inputSignals[1]->ready());
		space = min(outputSignals[0]->space(), outputSignals[1]->space());
	} else {
		ready = inputSignals[0]->ready();
		space = outputSignals[0]->space();
	}

	int available = min(ready, space);
	int process = min(available, measuredIntervalSize - (int)measuredInterval.size());
	
	if (available == 0) {
		return false;
	}
	
	
	// Get values until the vector/array has the desired number of elements
	for (long int i = 0; i < process; i++) {
		inputSignals[0]->bufferGet(&inValueI);
		outputSignals[0]->bufferPut(inValueI);
		if (numberOfInputSignals == 2 && numberOfOutputSignals == 2) {
			inputSignals[1]->bufferGet(&inValueQ);
			outputSignals[1]->bufferPut(inValueQ);
			inValue= complex<double>(inValueI, inValueQ);
		}
		else {
			inValue=complex<double>(inValueI,0);
		}

		measuredInterval.insert(measuredInterval.end(), inValue);

	}
	
	if (measuredInterval.size() == measuredIntervalSize) {
		switch (method) {
			case powerSpectrum:
			{
				// Get Welch's PSD estimate
				int start = 0;
				int finish = start + segmentSize;
				int summed = 0;
				vector<double> periodogramSum;
				vector<double> periodogramTmp(segmentSize);
		

				while (finish < (int)measuredInterval.size()) {
					// Create segment from full interval
					segmentComplex.assign(measuredInterval.begin() + start, measuredInterval.begin() + finish);
			

					// Multiply by window (in time domain)
					for (long int i = 0; i < segmentSize; i++) {
						segmentComplex[i] *= window[i];
					}

					// Create imaginary vector and generate complex segment
					/*if (numberOfInputSignals == 1) {
						for (unsigned int i = 0; i < segment.size(); i++)
						{
							// Imaginary data of the signal
							im[i] = 0;
						}
						segmentComplex = ReImVect2ComplexVector(segment, im);
					}*/
					// Get the FFT
					fourierTransformed = fft(segmentComplex);
					fourierTransformed = fftshift(fourierTransformed);
					double absFFTi = 0;
					for (unsigned int i = 0; i < fourierTransformed.size(); i++) {
						absFFTi = abs(fourierTransformed[i]);
						periodogramTmp[i] = pow(absFFTi, 2) / (U*segmentSize);
					}

					// Add to summing vector
					if (periodogramSum.empty()) {
						periodogramSum = periodogramTmp;
					} else {
						for (unsigned int i = 0; i < periodogramTmp.size(); i++) {
							periodogramSum[i] += periodogramTmp[i];
						}
					}
					summed += 1;
					segment.clear();
					//periodogramTmp.clear();
					fourierTransformed.clear();
					segmentComplex.clear();
					start += segmentSize - overlapCount;
					finish += segmentSize - overlapCount;
				}

				vector<double> signalPsd;
				vector<double> noisePsd;
		
				// Divide by number of segments used, and separate the signal frequencies from the rest
				for (unsigned int i = 0; i < periodogramTmp.size(); i++) {
					periodogramSum[i] = periodogramSum[i] / summed;
					if ((frequencies[i] < 0.5*(1+rollOffComp) / symbolPeriod) && (frequencies[i] > -0.5*(1 + rollOffComp) / symbolPeriod)) {
						signalPsd.insert(signalPsd.end(), periodogramSum[i]);
					} else {
						noisePsd.insert(noisePsd.end(), periodogramSum[i]);
					}
				}

				// Calculate overall noise and signal power
				// Assume that noise is uniformly distributed and that there is noise all over the spectrum
				for (unsigned int i = 1; i < noisePsd.size(); i++) {
					noisePower += (noisePsd[i - 1] + noisePsd[i]) / 2;
				}

				for (unsigned int i = 1; i < signalPsd.size(); i++) {
					signalPower += (signalPsd[i - 1] + signalPsd[i]) / 2;
				}
				signalPower = signalPower - noisePower * signalPsd.size() / noisePsd.size();
				noisePower = noisePower * periodogramSum.size() / noisePsd.size();
					if (signalPower <= 0) {
					cout << "ERROR: SNR too low, cannot identify the signal within the noise" << "\n";
				} else {
					allSNR.insert(allSNR.end(), signalPower / noisePower);
					cout << "SNR: " << 10 * (log10(signalPower) - log10(noisePower)) << "\n";
				}

				/* Calculating average SNR and bounds */
				if (!allSNR.empty()) {
			

					for (unsigned int i = 0; i < allSNR.size(); i++) {
						SNR += allSNR[i];
					}
					SNR = SNR/allSNR.size();
					for (unsigned int i = 0; i < allSNR.size(); i++) {
						stdSNR += pow((SNR - allSNR[i]), 2);
					}
					if (allSNR.size() > 1) {
						stdSNR = sqrt(stdSNR / (allSNR.size() - 1));
					}
					else {
						stdSNR = 0;
					}
			
					if (allSNR.size() > 1) {
						LowerBound = 10 * log10(SNR - z * stdSNR / sqrt(allSNR.size()));
						UpperBound = 10 * log10(SNR + z * stdSNR / sqrt(allSNR.size()));
					} else {
						LowerBound = 0;
						UpperBound = 0;
					}
					SNR = 10 * log10(SNR);
		//			if (LowerBound<lowestMinorant) {
		//					LowerBound = lowestMinorant;
		//				}

				/* Outputting a .txt report*/
					ofstream myfile;
					myfile.open(filename);
		//			myfile.open("SNR.txt", std::ios_base::app);
					myfile << "SNR= " << SNR << "\n";
					myfile << "Upper and lower confidence bounds for " << (1 - alpha) * 100 << "% confidence level \n";
					myfile << "Upper Bound= " << UpperBound << "\n";
					myfile << "Lower Bound= " << LowerBound << "\n";
					myfile << "Number of measurements= " << allSNR.size() << "\n";
					myfile.close();
				}
				measuredInterval.clear();
				noisePower = 0;
				signalPower = 0;
				break;
			}
			case constantAmplitudeMoments:
			{
				
				// Identify the symbols (points of constant amplitude)
				
				// Get the average of the absolute value (square root of signal power)

				// Get noise power by subtracting to average signal power (signal variance)

				// Divide signal power by noise power, get log and do stuff for interval
				break;
			}
			case m2m4: 
			{
				// I think it requires complex signal
				break;
			}
			case qFactor:
			{
/*				if (inputSignals[1]->getType != typeid(Binary) && inputSignals[2]->getType != typeid(Binary)) {
					throw std::invalid_argument("Either the second or third signals should contain the binary signal.");
					break;
				} else if (inputSignals[2]->getType == typeid(Binary) && inputSignals[1]->getType != typeid(TimeContinuousAmplitudeContinuousReal)) {
					throw std::invalid_argument("Wrong signal types for calculating Q-Factor.");
					break;
				}

				int samples1 = 0;
				double mu1 = 0;
				double sigma1 = 0;
				int samples0 = 0;
				double mu0 = 0;
				double sigma0 = 0;
				double qFactor = 0;
				int bitIdx = 0;

				for (long int i = 0; i < segmentSize; i++) {
					if (i % sps == 0) {								// Identify symbols (assuming sps is integer, currently mandatory)
						if (bitValue == 1) {
							samples1 += 1;
							mu1 += segment[i];
						}
						else {
							samples0 += 1;
							mu0 += segment[i];
						}
					}
				}

				mu1 = mu1 / samples1;
				mu0 = mu0 / samples0;

				for (long int i = 0; i < segmentSize; i++) {
					if (i % sps == 0) {								// Identify symbols (assuming sps is integer, currently mandatory)
						if (bitValues[bitIdx] == 1) {
							sigma1 += (segment[i] - mu1) * (segment[i] - mu1);
							bitIdx += 1;
						}
						else {
							sigma0 += (segment[i] - mu0) * (segment[i] - mu0);
							bitIdx += 1;
						}
					}
				}

				sigma1 = sqrt(sigma1 / (samples1 - 1));
				sigma0 = sqrt(sigma0 / (samples0 - 1));
				
				// Requires the bit sequence to work, as it would be necessary to identify the symbol values
				// Read the bit sequence

				qFactor = (mu1 - mu0)/(sigma1 + sigma0);
				allSNR.insert(allSNR.end(), qFactor);
*/				
				break;
			}
			}
	}
	
	return true;
}


vector<double> SNREstimator::getWindow(WindowType windowType, int windowSize) {
	vector<double> wn(windowSize);
	switch (windowType)
	{
		case Hamming:
			for (int x = 0; x < windowSize; x++) {
				wn[x] = 0.54 - 0.46*cos(2 * PI*x / (windowSize - 1));
			}
			return wn;

		case Hanning:
			for (int x = 0; x < windowSize; x++) {
				wn[x] = 0.5 *(1 - cos(2 * PI*x / (windowSize - 1)));
			}
			return wn;
	}
	return wn;
}

// NOT YET INCLUDED IN THE FFT ".CPP". REMOVE WHEN IT ARRIVES
vector<complex<double>> SNREstimator::fftshift(vector<complex<double>> &vec)
{
	unsigned long long N = vec.size();
	vector<complex<double>> output;

	if (N % 2 == 0)
	{
		for (unsigned long long i = N / 2; i < vec.size(); i++)
		{
			output.push_back(vec[i]);
		}

		for (unsigned long long i = 0; i < N / 2; i++)
		{
			output.push_back(vec[i]);
		}
	}
	else
	{
		N = N + 1;
		for (unsigned long long i = N / 2; i < vec.size(); i++)
		{
			output.push_back(vec[i]);
		}

		for (unsigned long long i = 0; i < N / 2; i++)
		{
			output.push_back(vec[i]);
		}

	}

	return output;

}