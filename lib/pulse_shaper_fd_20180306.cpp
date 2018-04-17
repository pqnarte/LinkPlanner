# include "netxpto.h"
# include "pulse_shaper_fd_20180306.h"
# include "overlap_save_20180208.h"
# include "fft_20180208.h"



using namespace std;

void raisedCosineTF(vector<t_complex> &transferFunction, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod);
void rootRaisedCosineTF(vector<t_complex> &transferFunction, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod);
void     gaussianTF(vector<t_complex> &transferFunction, int transferFunctionLength, double BTs,           double samplingPeriod, double symbolPeriod);


void PulseShaperFd::initialize(void) {

	double samplingPeriod = inputSignals[0]->samplingPeriod;
	double symbolPeriod = inputSignals[0]->symbolPeriod;

	transferFunctionLength = (int)floor(transferFunctionFrequencyLength * symbolPeriod / samplingPeriod);
	transferFunction.resize(transferFunctionLength);
	
	switch (getFilterType()) {

		case RaisedCosineTF:
			raisedCosineTF(transferFunction, getTransferFunctionLength(), rollOffFactor, samplingPeriod, symbolPeriod);
			break;
		case RootRaisedCosineTF:
			rootRaisedCosineTF(transferFunction, getTransferFunctionLength(), rollOffFactor, samplingPeriod, symbolPeriod);
			break;
		case GaussianTF:
			gaussianTF(transferFunction, getTransferFunctionLength(), BTs, samplingPeriod, symbolPeriod);
			break;
	};

	initializeFD_Filter();

}


void raisedCosineTF(vector<t_complex> &transferFunction, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod) {

	/*double cond1_if = (1 - rollOffFactor) / (2 * symbolPeriod);
	double cond2_if = (1 + rollOffFactor) / (2 * symbolPeriod);

	t_complex transferFunction_normFactor(0);
	vector<t_real> freqHz(transferFunctionLength, (t_real) 0.0);

	for (int i = 0; i < transferFunctionLength; i++) {
		freqHz.at(i) = -(1 / (samplingPeriod * 2)) + i*(1 / (samplingPeriod * transferFunctionLength));
		if (abs(freqHz.at(i)) <= (cond1_if)) {
			transferFunction[i] = 1.0;
		}
		else if ((abs(freqHz.at(i))>cond1_if) && (abs(freqHz.at(i)) <= cond2_if)){
			transferFunction[i] = (1.0 / 2.0)*(1.0 + cos((PI*symbolPeriod / rollOffFactor)*(abs(freqHz.at(i)) - ((1.0 - rollOffFactor) / (2.0 * symbolPeriod)))));

		}
		else {
			transferFunction[i] = 0;
		}
		//transferFunction_normFactor +=  (transferFunction[i] * transferFunction[i]);
	};

	// Normalization to unit energy
	//for (int i = 0; i < transferFunctionLength; i++) {
	//	transferFunction[i] = transferFunction[i] / sqrt(transferFunction_normFactor);
	//}*/
	t_real Ts = symbolPeriod;
	t_real T = samplingPeriod;

	t_real fWindow = 1 / samplingPeriod;
	t_real df = fWindow / transferFunctionLength;

	t_real f;
	vector<t_real> fSpan;
	for (int k = 0; k < transferFunctionLength; k++){
		f = -fWindow / 2 + k * df;
		fSpan.push_back(f);
	}

	vector<t_real> transferFunctionReal;
	for (unsigned int i = 0; i < fSpan.size(); i++)
	{
		// Calculate the transferFunctionAux 
		t_real negativeLimit = (1 - rollOffFactor) / (2 * Ts);
		t_real positiveLimit = (1 + rollOffFactor) / (2 * Ts);

		if (abs(fSpan[i]) <= negativeLimit)
		{
			transferFunctionReal.push_back(1);
		}
		else if (negativeLimit < abs(fSpan[i]) && abs(fSpan[i]) <= positiveLimit)
		{
			t_real value;
			value = 0.5*(1 + cos((PI*Ts / rollOffFactor) * (abs(fSpan[i]) - ((1 - rollOffFactor) / (2 * Ts)))));
			//value = (symbolPeriod/samplingPeriod)*0.5*(1 + cos((PI*Ts / rollOffFactor) * (abs(fSpan[i]) - ((1 - rollOffFactor) / (2 * Ts)))));
			//value = 0.5*(1 + cos( PI*((2*Ts*abs(fSpan[i]))-1+rollOffFactor) / (2*rollOffFactor)) ); // Rappaport Book
			transferFunctionReal.push_back(value);
		}
		else
		{
			transferFunctionReal.push_back(0);
		}
	}

	// convert transferFunctionAux to complex value
	vector<t_complex> transferFunctionComplex;
	vector<t_real> imTfn(transferFunctionReal.size());
	transferFunctionComplex = reImVect2ComplexVector(transferFunctionReal, imTfn);

	transferFunction = (transferFunctionComplex);

}

void rootRaisedCosineTF(vector<t_complex> &transferFunction, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod) {

	t_real Ts = symbolPeriod;
	t_real T = samplingPeriod;

	t_real fWindow = 1 / samplingPeriod;
	t_real df = fWindow / transferFunctionLength;

	t_real f;
	vector<t_real> fSpan;
	for (int k = 0; k < transferFunctionLength; k++) {
		f = -fWindow / 2 + k * df;
		fSpan.push_back(f);
	}

	vector<t_real> transferFunctionReal;
	for (unsigned int i = 0; i < fSpan.size(); i++)
	{
		// Calculate the transferFunctionAux 
		t_real negativeLimit = (1 - rollOffFactor) / (2 * Ts);
		t_real positiveLimit = (1 + rollOffFactor) / (2 * Ts);

		if (abs(fSpan[i]) <= negativeLimit)
		{
			transferFunctionReal.push_back(sqrt(symbolPeriod));
		}
		else if (negativeLimit < abs(fSpan[i]) && abs(fSpan[i]) <= positiveLimit)
		{
			t_real value;
			value = sqrt(symbolPeriod* 0.5*(1 + cos((PI*Ts / rollOffFactor) * (abs(fSpan[i]) - ((1 - rollOffFactor) / (2 * Ts))))));
			//value = 0.5*(1 + cos( PI*((2*Ts*abs(fSpan[i]))-1+rollOffFactor) / (2*rollOffFactor)) ); // Rappaport Book
			transferFunctionReal.push_back(value);
		}
		else
		{
			transferFunctionReal.push_back(0);
		}
	}

	// convert transferFunctionAux to complex value
	vector<t_complex> transferFunctionComplex;
	vector<t_real> imTfn(transferFunctionReal.size());
	transferFunctionComplex = reImVect2ComplexVector(transferFunctionReal, imTfn);

	transferFunction = transferFunctionComplex;

}

void gaussianTF(vector<t_complex> &transferFunction, int transferFunctionLength, double BTs, double samplingPeriod, double symbolPeriod)
{
	t_real Ts = symbolPeriod;
	t_real T = samplingPeriod;
	t_real fWindow = 1 / T;
	t_real df = fWindow / transferFunctionLength;

	t_real f;
	vector<t_real> fSpan;
	for (int k = 0; k < transferFunctionLength; k++) {
		f = -fWindow / 2 + k * df;
		fSpan.push_back(f);
	}

	//t_real BTs = 1;
	t_real a = (sqrt(log(2) / 2) / BTs)*Ts;

	vector<t_real> transferFunctionReal;
	for (unsigned int i = 0; i < fSpan.size(); i++)
	{
		// Calculate the transferFunctionAux
		t_real value = exp(-a*a*fSpan[i] * fSpan[i]);
		transferFunctionReal.push_back(value);
	}

	// convert transferFunctionAux to complex value
	vector<t_complex> transferFunctionComplex;
	vector<t_real> imTfn(transferFunctionReal.size());
	transferFunctionComplex = reImVect2ComplexVector(transferFunctionReal, imTfn);

	transferFunction = transferFunctionComplex;

	/*ofstream gaussTransferF("gaussTransferFunction.txt");
	for (size_t i = 0; i < transferFunctionComplex.size(); i++)
	{
		gaussTransferF << transferFunctionComplex[i].real() << "\n";
	}
	gaussTransferF.close();*/

}



