void Filter::initializeFIR_Filter(void) {
	if(filterDomain=="time")
	
	///////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////// TIME //////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	{
	outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
	outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
	outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;

	if (!getSeeBeginningOfImpulseResponse()) {
		int aux = (int)(((double)impulseResponseLength) / 2) + 1;
		outputSignals[0]->setFirstValueToBeSaved(aux);
	}

	delayLine.resize(impulseResponseLength, 0);

	if (saveImpulseResponse) {
		ofstream fileHandler("./signals/" + impulseResponseFilename, ios::out);
		fileHandler << "// ### HEADER TERMINATOR ###\n";

		t_real t;
		double samplingPeriod = inputSignals[0]->samplingPeriod;
		for (int i = 0; i < impulseResponseLength; i++) {
			t = -impulseResponseLength / 2 * samplingPeriod + i * samplingPeriod;
			fileHandler << t << " " << impulseResponse[i] << "\n";
		}
		fileHandler.close();
	}

	}


	else
	///////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////// FREQ //////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	{
		outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
		outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
		outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;

		/*	if (!getSeeBeginningOfImpulseResponse()) {
		int aux = (int)(((double)impulseResponseLength) / 2) + 1;
		outputSignals[0]->setFirstValueToBeSaved(aux);
		}*/

		/*	delayLine.resize(impulseResponseLength, 0);*/


		inputBufferTimeDomain.resize(inputBufferTimeDomainLength);
		outputBufferTimeDomain.resize(inputBufferTimeDomainLength);

		inputBufferPointer = inputBufferTimeDomainLength / 2;
		outputBufferPointer = inputBufferTimeDomainLength;

		//raisedCosineTF(transferFunction, transferFunctionLength, rollOffFactor, samplingPeriod, symbolPeriod);

		if (saveTransferFunction) {
			ofstream fileHandler("./signals/" + transferFunctionFilename, ios::out);
			fileHandler << "// ### HEADER TERMINATOR ###\n";

			double samplingPeriod = inputSignals[0]->samplingPeriod;
			t_real fWindow = 1 / samplingPeriod;
			t_real df = fWindow / transferFunctionLength;

			t_real f;
			for (int k = 0; k < transferFunctionLength; k++) {
				f = -fWindow / 2 + k * df;
				fileHandler << f << " " << transferFunction[k] << "\n";
				//fileHandler << transferFunction[k].real() << "\n";
				//fileHandler << transferFunction[k].imag() << "\n";
				
			}
			fileHandler.close();
		}

	}
};

bool Filter::runBlock(void) {

	if(filterDomain == "time")
	{
	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process == 0) return false;

	for (int i = 0; i < process; i++) {
		t_real val;
		(inputSignals[0])->bufferGet(&val);
		if (val != 0) {
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
	{
		bool alive{ false };

		int ready = inputSignals[0]->ready();
		int space = outputSignals[0]->space();

		int process = min(ready, space);

		if (process == 0) return false;

		vector<t_real> re(process);
		vector<t_real> im(process);
		vector<t_complex> IN(process);
		vector<t_complex> OUT(process);
		t_real input;
		vector<double> inputBufferTimeDomain(process);


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

		IN = ReImVect2ComplexVector(re, im); // Signal

		vector<t_real> rehn(impulseResponse.size());
		vector<t_real> imhn(impulseResponse.size());

		for (int i = 0; i < impulseResponse.size(); i++)
		{
			rehn[i] = impulseResponse.at(i);			// Real part of input
			imhn[i] = 0;								// Imaginary part which is manipulated as "0"
		}

		vector<t_complex> hn = ReImVect2ComplexVector(rehn, imhn);

		OUT = overlapSave(IN, hn);


		for (int i = 0; i < process; i++)					// Put the data using bufferput
		{
			t_real val;
			val = OUT[i].real();
			outputSignals[0]->bufferPut((t_real)(val));
		}


		return true;

	}
};