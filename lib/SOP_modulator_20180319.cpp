#include "SOP_modulator_20180319.h"

void SOPModulator::initialize(void) {

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

}

bool SOPModulator::runBlock(void) {
	bool alive{ false };

	int ready = inputSignals[0]->ready(); //clock
	
	int space0 = outputSignals[0]->space();
	int space1 = outputSignals[1]->space();
	int space = min(space0, space1);

	int process = min(ready, space);

	if (process <= 0) return alive;

	else {
		for (auto k = 0; k < process; k++) {
			switch (sopType)
			{
			case Deterministic:
				outputSignals[0]->bufferPut((t_real)theta);
				outputSignals[1]->bufferPut((t_real)phi);

				alive = true;
				break;

			case Stocastic:
				break;

			default:
				break;
			}
		}
	}
	
	return alive;
}
