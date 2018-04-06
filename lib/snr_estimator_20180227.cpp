#include <algorithm>
#include <complex>
#include "fft_20180208.h"
#include "netxpto_20180118.h"
#include "snr_estimator_20180227.h"

void SNREstimator::initialize(void) {
	firstTime = false;

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}

bool SNREstimator::runBlock(void) {
	// If its the first pass, calculate z for finding the confidence interval.
	// Also, calculate the window to be used.
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

		window = getWindow(windowType, measuredIntervalSize);
		
		double U = 0;	// Window normalization constant
		for (int i = 0; i < window.size(); i++) {
			U += pow(window[i], 2);
		}
		U = U / window.size();
	}

	t_real inValue;
	vector<double> segment;
	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();
	int available = min(ready, space);
	vector <double> im(segmentSize);
	vector <complex<double>> segmentComplex(segmentSize);
	vector <complex<double>> fourierTransformed;

	int process = min(available, measuredIntervalSize - (int)measuredInterval.size());
	
	// Get values until the vector/array has the desired number of elements
	for (long int i = 0; i < process; i++) {
		inputSignals[0]->bufferGet(&inValue);
		outputSignals[0]->bufferPut(inValue);
		measuredInterval.insert(measuredInterval.end(), inValue);
	}
	
	if (measuredInterval.size == measuredIntervalSize) {
		int start = 0;
		int finish = start + segmentSize;

		while (finish < measuredInterval.size()) {
			// Create segment from full interval
			segment.assign(measuredInterval.begin() + start, measuredInterval.begin() + finish);
			

			// Multiply by window (in time domain)
			for (long int i = 0; i < measuredIntervalSize; i++) {
				segment[i] *= window[i];
			}

			// Create imaginary vector and generate complex segment
			for (unsigned int i = 0; i < segment.size(); i++)
			{
				// Imaginary data of the signal
				im[i] = 0;
			}
			segmentComplex = ReImVect2ComplexVector(segment, im);
			fourierTransformed = fft(segmentComplex);
			fourierTransformed = fftshift(fourierTransformed);
		}









	}
			
	
	return true;
}

vector<double> getWindow(WindowType windowType, int windowSize) {
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
	}
}

/*vector<double> psdWelch(vector<double> signalInterval, int segmentSize, int overlapSize) {


	periodogramSum = zeros(segSize, 1);
	summed = 0;

	psdWv = ((-segSize / 2 + 1:segSize / 2) / segSize) * 1 / signal.samplingPeriod;
	snrArray = [];

	while max(idxSegment) < length(signal.data)
		sigSegment = signal.data(idxSegment);


	tmpPer = fft(segWn);
	tmpPer = abs(fftshift(tmpPer)). ^ 2 / (U*segSize);
	%     tmpPer = tmpPer;
	periodogramSum = periodogramSum + tmpPer';
		tmpSNR = snrFromPsd(tmpPer, psdWv, signal);
	%     disp(['instSNR: ' num2str(tmpSNR)])
		snrArray = [snrArray tmpSNR];
	summed = summed + 1;
	idxSegment = idxSegment + segSize - overlap;
	end
}
//}
double getSNR() {

}*/