#include <algorithm>
#include <complex>
#include <iostream>
#include <fstream>
#include <string>

#include "netxpto_20180118.h"
#include "hamming_coder_20180608.h"

using namespace std;

void HammingCoder::initialize(void){

	//matriz

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSymbolPeriod());
}


bool HammingCoder::runBlock(void) {

	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSymbolPeriod());
	numberOfInputSignals = (int)inputSignals.size();

	bool alive{ false };

	
	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process == 0) return false;

		int samplesPerSymbol = (int)inputSignals[0]->getSamplesPerSymbol();
		for (int k = 0; k < process; k++) {
			t_real in;
			inputSignals[0]->bufferGet(&in);
			//cout << in << endl;
			//cout << inputSignals[0]->getOutPosition() << endl;
			if (count % samplesPerSymbol == 0) {
				outputSignals[0]->bufferPut((t_real)in);
			}
			count++;
		}

	}
	//Sampler with external clock
	else {

		int ready = inputSignals[0]->ready();
		int space = outputSignals[0]->space();
		int process = min(ready, space);

		if (process <= 0) return false;

		t_real inClock;
		t_real inSignal;

		for (int k = 0; k < process; k++) {

			inputSignals[1]->bufferGet(&inClock);
			inputSignals[0]->bufferGet(&inSignal);

			if (inClock == 1.0) {

				outputSignals[0]->bufferPut((t_real)inSignal);
			}

		}
		
		return true;
	}

	return alive;
}
