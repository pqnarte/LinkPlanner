#include "detection_decision_circuit_20180206.h"

void DetectionDecisionCircuit::initialize(void) {

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}

bool DetectionDecisionCircuit::runBlock(void) {

	int ready1 = inputSignals[0]->ready();
	int ready2 = inputSignals[0]->ready();
	int ready = min(ready1, ready2);

	int space = outputSignals[0]->space();
	
	int process = min(ready, space);

	if (process <= 0) return false;

	for (auto k = 0; k < process; k++) {
		t_real value0;
		inputSignals[0]->bufferGet(&value0);

		t_real value1;
		inputSignals[1]->bufferGet(&value1);

		if ((value0 == 1) && (value1 == 0)) {
			outputSignals[0]->bufferPut((t_binary)0);
		}
		else if ((value0 == 0) && (value1 == 1)) {
			outputSignals[0]->bufferPut((t_binary)1);
		}
		else if ((value0 == 1) && (value1 == 1)) {
			outputSignals[0]->bufferPut((t_binary)2);
		}
		else
			outputSignals[0]->bufferPut((t_binary)3);
	}

	return true;
}