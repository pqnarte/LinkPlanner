#include "bobBB84_20180206.h"

void bobBB84::initialize(void) {

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[1]->setSymbolPeriod(inputSignals[1]->getSymbolPeriod());
	outputSignals[1]->setSamplingPeriod(inputSignals[1]->getSamplingPeriod());
	outputSignals[1]->setSamplesPerSymbol(1);
	outputSignals[1]->setFirstValueToBeSaved(inputSignals[1]->getFirstValueToBeSaved());

}

bool bobBB84::runBlock(void) {
	
	int ready0 = inputSignals[0]->ready();
	int ready1 = inputSignals[1]->ready();
	int ready = min(ready0, ready1);
	ready = min(ready, messageDataLength);

	int space0 = outputSignals[0]->space();
	int space1 = outputSignals[1]->space();
	int space = min(space0, space1);

	int process = min(ready, space);

	if (process < 0) return false;

	string messageDataOut;
	for (auto k = 0; k < process; k++) {
		t_binary basisIn;
		inputSignals[0]->bufferGet(&basisIn);
		t_real measurement;
		inputSignals[1]->bufferGet(&measurement);

		if ((measurement == 0.0) || (measurement == 1.0)) {
			messageDataOut.append(to_string(basisIn));
			outputSignals[0]->bufferPut((t_binary)basisIn);
		}
		else {
			messageDataOut.append(to_string(measurement));
			//discard -1 and -2
		}
	}
	t_message messageOut;
	setMessageData(messageOut, messageDataOut);
	setMessageDataLength(messageOut, to_string(process));

	return true;
}
