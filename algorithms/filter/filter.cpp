# include "filter.h"
# include "overlapSave_20180208.h"

void FilterRoot::initializeFilterRoot(void)
{
	if (filterDomain == "time")
	{
		/////////////////////////////////// TIME //////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////
		outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
		outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
		outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;

		if (!getSeeBeginningOfImpulseResponse()) {
			int aux = (int)(((double)impulseResponseLength) / 2) + 1;
			outputSignals[0]->setFirstValueToBeSaved(aux);
		}

		delayLine.resize(impulseResponseLength, 0);

		if (saveImpulseResponse)
		{
			ofstream fileHandler("./signals/" + impulseResponseFilename, ios::out);
			fileHandler << "// ### HEADER TERMINATOR ###\n";

			t_real t;
			double samplingPeriod = inputSignals[0]->samplingPeriod;
			for (int i = 0; i < impulseResponseLength; i++)
			{
				t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;
				fileHandler << t << " " << impulseResponse[i] << "\n";
			}
			fileHandler.close();
		}

	}

	else
		/////////////////////////////////// FREQ //////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////
	{
		outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
		outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
		outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;

		if (!getSeeBeginningOfImpulseResponse()) {
			int aux = (int)(((double)impulseResponseLength) / 2) + 1;
			outputSignals[0]->setFirstValueToBeSaved(aux);
		}

		if (saveTransferFunction)
		{
			ofstream fileHandler("./signals/" + transferFunctionFilename, ios::out);
			fileHandler << "// ### HEADER TERMINATOR ###\n";

			double samplingPeriod = inputSignals[0]->samplingPeriod;
			t_real fWindow = 1 / samplingPeriod;
			t_real df = fWindow / transferFunction.size();

			t_real f;
			for (int k = 0; k < transferFunction.size(); k++) 
			{
				f = -fWindow / 2 + k * df;
				fileHandler << f << " " << transferFunction[k] << "\n";
			}
			fileHandler.close();
		}

	}
};


bool FilterRoot::runBlock(void) {

	/////////////////////////////////// TIME //////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	if (filterDomain == "time")
	{
		int ready = inputSignals[0]->ready();
		int space = outputSignals[0]->space();
		int process = min(ready, space);
		if (process == 0) return false;


		for (int i = 0; i < process; i++) 
		{
			t_real val;
			(inputSignals[0])->bufferGet(&val);

			if (val != 0)
			{
				vector<t_real> aux(impulseResponseLength, 0.0);
				transform(impulseResponse.begin(), impulseResponse.end(), aux.begin(), bind1st(multiplies<t_real>(), val));
				transform(aux.begin(), aux.end(), delayLine.begin(), delayLine.begin(), plus<t_real>());
			}
			outputSignals[0]->bufferPut((t_real)(delayLine[0]));
			rotate(delayLine.begin(), delayLine.begin() + 1, delayLine.end());
			delayLine[impulseResponseLength - 1] = 0.0;
		}
	
		return true;
	}

	else
		/////////////////////////////////// FREQ /////////////////////////////
		//////////////////////////////////////////////////////////////////////
	{
		bool alive{ false };

		int ready = inputSignals[0]->ready();
		int space = outputSignals[0]->space();
		int process = min(ready, space);
		if (process == 0) return false;

		vector<t_real> re(process);
		vector<t_real> im(process);
		vector<t_complex> IN1(process);
		vector<t_complex> OUTaux;
		vector<t_complex> OUT;
		t_real input;
		vector<double> inputBufferTimeDomain(process);
		vector<t_complex>  currentCopyAux;
		
		/////////////////////// previousCopy & currentCopy /////////////////////
		////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < process; i++)               // Get the Input signal 
		{
			inputSignals[0]->bufferGet(&input);
			inputBufferTimeDomain.at(i) = input;
		}
	

		for (int i = 0; i < process; i++)
		{
			re[i] = inputBufferTimeDomain.at(i); // Real part of input
			im[i] = 0;				// Imaginary part which is manipulated as "0"
		}
		currentCopyAux = ReImVect2ComplexVector(re, im);// currentCopy complex form
										
		
		vector<t_complex> pcInitialize(process);
		if (K == 0)									// For the first data block only
		{
			previousCopy = pcInitialize;			// PREVIOUS COPY
		}

		// size modification of currentCopyAux to currentCopy.
		vector<t_complex> currentCopy(previousCopy.size());	
		for (unsigned int i = 0; i < currentCopyAux.size(); i++)
		{
			currentCopy[i] = currentCopyAux[i];
		}

		/////////////////////////// Filter Data "hn" //////////////////////////
		///////////////////////////////////////////////////////////////////////
		vector<t_real> rehn(impulseResponse.size());
		vector<t_real> imhn(impulseResponse.size());
		
		for (int i = 0; i < impulseResponse.size(); i++)
		{
			rehn[i] = impulseResponse.at(i);// Real part of input
			imhn[i] = 0;		// Imaginary part which is manipulated as "0"
		}

		vector<t_complex> hn = ReImVect2ComplexVector(rehn, imhn); // filter hn complex form

		////////////////////// OverlapSave in Realtime ///////////////////////
		//////////////////////////////////////////////////////////////////////
		OUTaux = overlapSaveRealTime(currentCopy, previousCopy, hn);    
		
		previousCopy = currentCopy;
		K = K + 1;
		
		// Discard the overlap data
		for ( int i = 0; i < process; i++)
		{
			OUT.push_back(OUTaux[previousCopy.size() + i]);
		}

		// Bufferput
		for ( int i = 0; i < process; i++)			
		{
			t_real val;
			val = OUT[i].real();
			outputSignals[0]->bufferPut((t_real)(val));
		}

		return true;

	}
};

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// pulseShaper //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
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

	transferFunctionLength = transferFunction.size();
	initialize_FilterRoot();
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
		gauss = exp(-t*t / (pulsewidth*pulsewidth / 36));
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
		transferFunction[i] = transferFunction[i] * (sqrt(static_cast<double>(impulseResponseAux.size())));
	}
};

void square(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, double samplingPeriod, double symbolPeriod, string &filterDomain) {

	int samplesPerSymbol = (int)(symbolPeriod / samplingPeriod);

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

	