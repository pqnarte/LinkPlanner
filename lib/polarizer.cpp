#include "netxpto.h"
#include "polarizer.h"

void Polarizer::initialize(void) {
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
}

bool Polarizer::runBlock(void) {
	int ready1 = inputSignals[0]->ready();
	int ready2 = inputSignals[1]->ready();

	int ready = min(ready1, ready2);

	int space = outputSignals[0]->space();

	int length = min(ready, space);

	if (length <= 0) return false;


	t_complex_xy valueXY;
	t_complex valueX, valueY;

	double pol;

	for (int i = 0; i < length; i++) {
		inputSignals[0]->bufferGet(&pol);
		inputSignals[1]->bufferGet(&valueXY);

		valueX = valueXY.x;
		valueY = valueXY.y;

		valueX = valueX * cos(-pol*PI / 180);
		valueY = valueX *(-sin(-pol*PI / 180));

		valueXY = { valueX, valueY };

		outputSignals[0]->bufferPut(valueXY);

	}

	return 0;
}

