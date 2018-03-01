# include "netxpto.h"
# include "pulse_shaper.h"
# include "fft_20180208.h"


using namespace std;

void raisedCosine(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain);
void gaussian(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain);
void square(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double samplingPeriod, double symbolPeriod, string &filterDomain);


void PulseShaper::initialize(void) {

	double samplingPeriod = inputSignals[0]->samplingPeriod;
	double symbolPeriod = inputSignals[0]->symbolPeriod;

	impulseResponseLength = (int)floor(impulseResponseTimeLength * symbolPeriod / samplingPeriod);
	impulseResponse.resize(impulseResponseLength);
	filterDomain = filterDomainType;

	switch (getFilterType()) {

		case RaisedCosine:
			raisedCosine(impulseResponse, transferFunction, impulseResponseLength, rollOffFactor, samplingPeriod, symbolPeriod, passiveFilterMode, filterDomain);
			break;
		case Gaussian:
			gaussian(impulseResponse, transferFunction, impulseResponseLength, rollOffFactor, samplingPeriod, symbolPeriod, passiveFilterMode, filterDomain);
			break;
		case Square:
			square(impulseResponse, transferFunction, impulseResponseLength, samplingPeriod, symbolPeriod, filterDomain);
			break;
	};

	initializeFIR_Filter();
}

void raisedCosine(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain) {
	double sinc;
	double gain{ 0 };
	for (int i = 0; i < impulseResponseLength; i++) {
		t_real t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;
		if (t != 0) {
			sinc = sin(PI * t / symbolPeriod) / (PI * t / symbolPeriod);
		}
		else {
			sinc = 1;
		}
		impulseResponse[i] = sinc*cos(rollOffFactor*PI*t / symbolPeriod) / (1 - (4.0 * rollOffFactor * rollOffFactor * t * t) / (symbolPeriod * symbolPeriod));
		gain = gain + impulseResponse[i];
	};
	if (passiveFilterMode)
	{
		for (int i = 0; i < impulseResponseLength; i++)
		{
			impulseResponse[i] = impulseResponse[i] / gain;
		}
	}

	vector<t_real> re(impulseResponse.size());
	vector<t_real> im(impulseResponse.size());

	for (unsigned int i = 0; i < impulseResponse.size(); i++)
	{
		re[i] = impulseResponse[i];
	}

	vector<complex<double>> impulseResponseAux = ReImVect2ComplexVector(re, im);
	transferFunction = fft(impulseResponseAux);

	for (unsigned int i = 0; i < impulseResponseAux.size(); i++)
	{
		transferFunction[i] = transferFunction[i] * (sqrt(static_cast<double>(impulseResponseAux.size())));
	}
	
};

void gaussian(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain) {
	double gauss;
	double pulsewidth = 5e-10;
	double gain{ 0 };
	for (int i = 0; i < impulseResponseLength; i++) {
		t_real t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;
		gauss = exp(-t*t / (pulsewidth*pulsewidth/36));
		impulseResponse[i] = gauss;
		gain = gain + impulseResponse[i];
	};
	if (passiveFilterMode)
	{
		for (int i = 0; i < impulseResponseLength; i++)
		{
			impulseResponse[i] = impulseResponse[i] / gain;
		}
	}

	vector<t_real> re(impulseResponse.size());
	vector<t_real> im(impulseResponse.size());

	for (unsigned int i = 0; i < impulseResponse.size(); i++)
	{
		re[i] = impulseResponse[i];
	}

	vector<t_complex> impulseResponseAux = ReImVect2ComplexVector(re, im);
	transferFunction = fft(impulseResponseAux);

	for (unsigned int i = 0; i < impulseResponseAux.size(); i++)
	{
		transferFunction[i] = transferFunction[i]* (sqrt(static_cast<double>(impulseResponseAux.size())));
	}
};

void square(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double samplingPeriod, double symbolPeriod, string &filterDomain) {

	int samplesPerSymbol = (int) (symbolPeriod / samplingPeriod);

	for (int k = 0; k < samplesPerSymbol; k++) {
		impulseResponse[k] = 1.0;
	};

	for (int k = samplesPerSymbol; k < impulseResponseLength; k++) {
		impulseResponse[k] = 0.0;
	};

	vector<t_real> re(impulseResponse.size());
	vector<t_real> im(impulseResponse.size());

	for (unsigned int i = 0; i < impulseResponse.size(); i++)
	{
		re[i] = impulseResponse[i];
	}

	vector<t_complex> impulseResponseAux = ReImVect2ComplexVector(re, im);
	 transferFunction = fft(impulseResponseAux);

	 for (unsigned int i = 0; i < impulseResponseAux.size(); i++)
	 {
		 transferFunction[i] = transferFunction[i] * (sqrt(static_cast<double>(impulseResponseAux.size())));
	 }
};
