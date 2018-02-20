#include "bobBB84_20180206.h"

void bobBB84::initialize(void) {

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
}

bool bobBB84::runBlock(void) {
	bool alive = true;

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process < 0) alive = false;

	else {
		for (int k = 0; k < process; k++) {
			t_real in;
			inputSignals[0]->bufferGet(&in);
			outputSignals[0]->bufferPut((t_real)in);
		}
	}

	return alive;
}
