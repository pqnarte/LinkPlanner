#include "netxpto.h"
#include "transform.h"



using namespace std;


void Transform::initialize(void)
{
	outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
	outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
	outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}

bool Transform::runBlock(void)
{

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();
	int process = min(ready, space);

	if (process <= 0) return false;

	t_real input;
	vector<double> inputBufferTimeDomain(process);
	vector <complex<double>> IN(process);
	vector <complex<double>> inputSignalFreqencyDomain(process);
	vector <double> outputSignalTimeDomain(process);

	ComplexMult C;
	FourierTransform FT;
		
	vector<double> re(process);
	vector<double> im(process);


	for (int i = 0; i < process; i++)					// Get the Input signal as a vector of size "n"
	{
		inputSignals[0]->bufferGet(&input);
		inputBufferTimeDomain.at(i) = input;
	}



	for (int i = 0; i < process; i++)
	{
		re[i] = inputBufferTimeDomain.at(i);			// Real part of input
		im[i] = 0;										// Imaginary part which is manipulated as "0"
	}



	IN = C.ReImVect2ComplexVector(re, im);				// Time domain complex form signal

	inputSignalFreqencyDomain = FT.transform(IN, -1);	// Fast Fourier Transform (FFT)

	

	for (int i = 0; i < process; i++)					// Put the data using bufferput

	{
		t_real OUT;
		OUT = inputSignalFreqencyDomain[i].real();
		outputSignals[0]->bufferPut((t_real)(OUT));
	}

	return true;

}