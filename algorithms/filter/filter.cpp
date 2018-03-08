# include "filter.h"
# include "overlapSave_20180208.h"
# include <algorithm>
# include <vector>
# include <algorithm>



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

		if (!getSeeBeginningOfTransferFunction()) {
			int aux = (int)(((double)transferFunctionLength) / 2) + 1;
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

		if (!getSeeBeginningOfTransferFunction()) {
			int aux = (int)(((double)transferFunctionLength) / 2) + 1;
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
		currentCopyAux = reImVect2ComplexVector(re, im);// currentCopy complex form


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

		vector<t_complex> hn = reImVect2ComplexVector(rehn, imhn); // filter hn complex form

																   ////////////////////// OverlapSave in Realtime ///////////////////////
																   //////////////////////////////////////////////////////////////////////
		OUTaux = overlapSaveRealTime(currentCopy, previousCopy, hn);

		previousCopy = currentCopy;
		K = K + 1;

		// Discard the overlap data
		for (int i = 0; i < process; i++)
		{
			OUT.push_back(OUTaux[previousCopy.size() + i]);
		}

		// Bufferput
		for (int i = 0; i < process; i++)
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
void raisedCosine(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain);
void gaussian(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain);
void square(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double samplingPeriod, double symbolPeriod, string &filterDomain);

void raisedCosineTfn(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain);
void gaussianTfn(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain);

void PulseShaper::initialize(void) {

	double samplingPeriod = inputSignals[0]->samplingPeriod;
	double symbolPeriod = inputSignals[0]->symbolPeriod;

	impulseResponseLength = (int)floor(impulseResponseTimeLength * symbolPeriod / samplingPeriod);
	transferFunctionLength = (int)floor(transferFunctionFrequencyLength * symbolPeriod / samplingPeriod);

	impulseResponse.resize(impulseResponseLength);
	transferFunction.resize(transferFunctionLength);
	filterDomain = filterDomainType;

	switch (getFilterType()) {

	case RaisedCosine:
		raisedCosine(impulseResponse, transferFunction, impulseResponseLength, transferFunctionLength, rollOffFactor, samplingPeriod, symbolPeriod, passiveFilterMode, filterDomain);
		break;
	case Gaussian:
		gaussian(impulseResponse, transferFunction, impulseResponseLength, transferFunctionLength, rollOffFactor, samplingPeriod, symbolPeriod, passiveFilterMode, filterDomain);
		break;
	case Square:
		square(impulseResponse, transferFunction, impulseResponseLength, transferFunctionLength, samplingPeriod, symbolPeriod, filterDomain);
		break;
	case RaisedCosineTfn:
		raisedCosineTfn(impulseResponse, transferFunction, impulseResponseLength, transferFunctionLength, rollOffFactor, samplingPeriod, symbolPeriod, passiveFilterMode, filterDomain);
		break;
	case GaussianTfn:
		gaussianTfn(impulseResponse, transferFunction, impulseResponseLength, transferFunctionLength, rollOffFactor, samplingPeriod, symbolPeriod, passiveFilterMode, filterDomain);
		break;
	};

	impulseResponseLength = (int)impulseResponse.size();		// It is due to update the size of impulseResponseLength
	transferFunctionLength = (int)transferFunction.size();	// It is due to update the size of transferFunctionLength

	initializeFilterRoot();
}

///////////////////////////////////////////////////////////////
///////////////////// Impulse Responses ///////////////////////
///////////////////////////////////////////////////////////////
void raisedCosine(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain) {
	double sinc;
	double gain{ 0 };
	ofstream dataImpulseT("dataImpulseT.txt");

	for (int i = 0; i < impulseResponseLength; i++) {
		t_real t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;
		dataImpulseT << t << "\n";
		if (t != 0) {
			sinc = sin(PI * t / symbolPeriod) / (PI * t / symbolPeriod);
		}
		else {
			sinc = 1;
		}
		impulseResponse[i] = sinc*cos(rollOffFactor*PI*t / symbolPeriod) / (1 - (4.0 * rollOffFactor * rollOffFactor * t * t) / (symbolPeriod * symbolPeriod));
		gain = gain + impulseResponse[i];
	};
	dataImpulseT.close();

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

	vector<complex<double>> impulseResponseAux = reImVect2ComplexVector(re, im);
	transferFunction = fft(impulseResponseAux);

	/////////////// Normalization of Response////////////////
	vector<t_real> absTransferFunction(transferFunction.size());
	for (int i = 0; i < transferFunction.size(); i++) { absTransferFunction[i] = abs(transferFunction[i]); }
	double maxValue = *std::max_element(absTransferFunction.begin(), absTransferFunction.end());


	for (unsigned int i = 0; i < impulseResponseAux.size(); i++)
	{
		transferFunction[i] = (1 / static_cast<double>(maxValue))*(static_cast<double>(samplingPeriod / symbolPeriod)*transferFunction[i] * (sqrt(static_cast<double>(impulseResponseAux.size()))));
	}


	ofstream dataImpulseIMP("dataImpulseIMP.txt");
	ofstream dataImpulseTFN("dataImpulseTFN.txt");
	for (unsigned int i = 0; i < impulseResponse.size(); i++)
	{
		dataImpulseIMP << impulseResponse[i] << "\n";
		dataImpulseTFN << transferFunction[i].real() << "\n";
	}
	dataImpulseIMP.close();
	dataImpulseTFN.close();

};

void gaussian(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain) {
	double gauss;
	double pulsewidth = 5e-10;
	double gain{ 0 };
	/*for (int i = 0; i < impulseResponseLength; i++) {
	t_real t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;
	gauss = exp(-t*t / (pulsewidth*pulsewidth / 36));
	impulseResponse[i] = gauss;
	gain = gain + impulseResponse[i];
	};*/
	t_real Ts = symbolPeriod;
	t_real T = samplingPeriod;
	t_real BTs = 1;
	t_real a = (sqrt(log(2) / 2)/BTs)*Ts;
	

	ofstream gaussImpulseT("gaussImpulseT.txt");
	for (int i = 0; i < impulseResponseLength; i++)
	{
		t_real t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;

		//gauss = (sqrt(PI)/a)*(exp(-(PI*t / a)*(PI*t / a)));
		gauss = (exp(-(PI*t / a)*(PI*t / a)));
		impulseResponse[i] = gauss;
		gaussImpulseT << t << "\n";
		gain = gain + impulseResponse[i];
	};
	gaussImpulseT.close();
	

	if (passiveFilterMode)
	{
		for (int i = 0; i < impulseResponseLength; i++)
		{
			impulseResponse[i] = impulseResponse[i] / gain;
		}
	}

	///////////////////////////////////////////////////////// TF //////////////////////////////////////////////////////////////////////////////////////////////	

	vector<t_real> im(impulseResponse.size());
	vector<t_complex> impulseResponseAux = reImVect2ComplexVector(impulseResponse, im);
	transferFunction = fft(impulseResponseAux);

	/////////////// Normalization of Response////////////////
	vector<t_real> absTransferFunction(transferFunction.size());
	for (int i = 0; i < transferFunction.size(); i++) { absTransferFunction[i] = abs(transferFunction[i]);}
	double maxValue = *std::max_element(absTransferFunction.begin(), absTransferFunction.end());
	

	for (unsigned int i = 0; i < impulseResponseAux.size(); i++)
	{
		transferFunction[i] = (1/ static_cast<double>(maxValue))*(static_cast<double>(samplingPeriod / symbolPeriod)*transferFunction[i] * (sqrt(static_cast<double>(impulseResponseAux.size()))));
	}

	/////////////// Write Response////////////////
	ofstream gaussImpulseIMP("gaussImpulseIMP.txt");
	ofstream gaussImpulseTFN("gaussImpulseTFN.txt");
	for (unsigned int i = 0; i < impulseResponse.size(); i++)
	{
		gaussImpulseIMP << impulseResponse[i] << "\n";
		gaussImpulseTFN << transferFunction[i].real() << "\n";
	}
	gaussImpulseIMP.close();
	gaussImpulseTFN.close();
};

void square(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double samplingPeriod, double symbolPeriod, string &filterDomain) {

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

	vector<t_complex> impulseResponseAux = reImVect2ComplexVector(re, im);
	transferFunction = fft(impulseResponseAux);

	for (unsigned int i = 0; i < impulseResponseAux.size(); i++)
	{
		transferFunction[i] = transferFunction[i] * (sqrt(static_cast<double>(impulseResponseAux.size())));
	}

};


///////////////////////////////////////////////////////////////
///////////////////// Transfer Function ///////////////////////
///////////////////////////////////////////////////////////////
void raisedCosineTfn(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain)
{
	t_real Ts = symbolPeriod;
	t_real T = samplingPeriod;

	t_real fWindow = 1 / samplingPeriod;
	t_real df = fWindow / transferFunctionLength;

	t_real f;
	vector<t_real> fSpan;
	ofstream dataTransferF("dataTransferF.txt");
	for (int k = 0; k < transferFunctionLength; k++)
	{
		f = -fWindow / 2 + k * df;
		fSpan.push_back(f);
		dataTransferF << f << "\n";
	}
	dataTransferF.close();


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
			transferFunctionReal.push_back(value);
		}
		else
		{
			transferFunctionReal.push_back(0);
		}


	}
	ofstream dataTransferTFN("dataTransferTFN.txt");
	for (unsigned int i = 0; i < transferFunctionReal.size(); i++)
	{
		dataTransferTFN << transferFunctionReal[i] << "\n";
	}
	dataTransferTFN.close();

	// convert transferFunctionAux to complex value
	vector<t_complex> transferFunctionComplex;
	vector<t_real> imTfn(transferFunctionReal.size());
	transferFunctionComplex = reImVect2ComplexVector(transferFunctionReal, imTfn);

	transferFunction = transferFunctionComplex;

	// Calculate the impulse response of the filter
	vector<t_complex> impulseResponseComplex(transferFunctionComplex.size());
	vector<t_real> impulseResponseAux(transferFunctionComplex.size());

	transferFunctionComplex = ifftshift(transferFunctionComplex); // ifftshift 
	impulseResponseComplex = ifft(transferFunctionComplex);		  // ifft	   
	impulseResponseComplex = fftshift(impulseResponseComplex);	  // fftshift 


	// Multiply it with the (symbolPeriod/samplingPeriod) to adjust the shape 
	vector<t_real> absImpulseResponse(impulseResponseComplex.size());
	for (int i = 0; i < impulseResponseComplex.size(); i++) { absImpulseResponse[i] = (impulseResponseComplex[i].real()); }
	double maxValue1 = *std::max_element(absImpulseResponse.begin(), absImpulseResponse.end());

	for (unsigned int i = 0; i < transferFunctionComplex.size(); i++) {
		//impulseResponseAux[i] = (sqrt(2)*PI)* impulseResponseComplex[i].real() / (sqrt(static_cast<double>(transferFunctionComplex.size())));
		impulseResponseAux[i] = (1 / maxValue1)*(symbolPeriod / samplingPeriod)*absImpulseResponse[i] / (sqrt(static_cast<double>(transferFunctionComplex.size())));
	}

	impulseResponse = impulseResponseAux;
	impulseResponseLength = (int)impulseResponse.size();

	ofstream dataTransferIMP("dataTransferIMP.txt");
	for (unsigned int i = 0; i < impulseResponse.size(); i++) {
		dataTransferIMP << impulseResponse[i] << "\n";
	}
	dataTransferIMP.close();

}

void gaussianTfn(vector<t_real> &impulseResponse, vector<t_complex> &transferFunction, int impulseResponseLength, int transferFunctionLength, double rollOffFactor, double samplingPeriod, double symbolPeriod, bool passiveFilterMode, string &filterDomain)
{
	t_real Ts = symbolPeriod;
	t_real T = samplingPeriod;
	t_real fWindow = 1 / T;
	t_real df = fWindow / transferFunctionLength;

	t_real f;
	vector<t_real> fSpan;
	ofstream gaussTransferF("gaussTransferF.txt");
	for (int k = 0; k < transferFunctionLength; k++) {
		f = -fWindow / 2 + k * df;
		fSpan.push_back(f);
		gaussTransferF << f << "\n";
	}
	gaussTransferF.close();

	t_real BTs = 1;
	t_real a = (sqrt(log(2) / 2) / BTs)*Ts;

	vector<t_real> transferFunctionReal;
	for (unsigned int i = 0; i < fSpan.size(); i++)
	{
		// Calculate the transferFunctionAux
		t_real value = exp(-a*a*fSpan[i] * fSpan[i]);
		//t_real value = exp(-(PI*PI*fSpan[i] * fSpan[i] / a));
		transferFunctionReal.push_back(value);
	}

	ofstream gaussTransferTFN("gaussTransferTFN.txt");
	for (unsigned int i = 0; i < transferFunctionReal.size(); i++) {
		gaussTransferTFN << transferFunctionReal[i] << "\n";
	}
	gaussTransferTFN.close();

	// convert transferFunctionAux to complex value
	vector<t_complex> transferFunctionComplex;
	vector<t_real> imTfn(transferFunctionReal.size());
	transferFunctionComplex = reImVect2ComplexVector(transferFunctionReal, imTfn);

	transferFunction = transferFunctionComplex;

	// Calculate the impulse response of the filter
	vector<t_complex> impulseResponseComplex(transferFunctionComplex.size());
	vector<t_real> impulseResponseAux(transferFunctionComplex.size());

	transferFunctionComplex = ifftshift(transferFunctionComplex); // ifftshift
	impulseResponseComplex = ifft(transferFunctionComplex);		  // ifft	
	impulseResponseComplex = fftshift(impulseResponseComplex);	  // fftshift

																 


	vector<t_real> absImpulseResponse(impulseResponseComplex.size());
	for (int i = 0; i < impulseResponseComplex.size(); i++) { absImpulseResponse[i] = (impulseResponseComplex[i].real()); }
	double maxValue1 = *std::max_element(absImpulseResponse.begin(), absImpulseResponse.end());

	// Multiply it with the (symbolPeriod/samplingPeriod) to adjust the shape 

	for (unsigned int i = 0; i < transferFunctionComplex.size(); i++) {
		//impulseResponseAux[i] = (sqrt(2)*PI)* impulseResponseComplex[i].real() / (sqrt(static_cast<double>(transferFunctionComplex.size())));
		impulseResponseAux[i] = (1/ maxValue1)*(symbolPeriod/samplingPeriod)*absImpulseResponse[i] / (sqrt(static_cast<double>(transferFunctionComplex.size())));
	}


	impulseResponse = impulseResponseAux;
	impulseResponseLength = (int)impulseResponse.size();

	ofstream gaussTransferIMP("gaussTransferIMP.txt");
	for (unsigned int i = 0; i < impulseResponse.size(); i++) {
		gaussTransferIMP << impulseResponse[i] << "\n";
	}
	gaussTransferIMP.close();


}