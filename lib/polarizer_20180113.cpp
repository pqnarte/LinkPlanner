#include "netxpto.h"
#include "polarizer_20180113.h"

void Polarizer::initialize(void) {
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
}

bool Polarizer::runBlock(void) {
	int ready0 = inputSignals[0]->ready();
	int ready1 = inputSignals[1]->ready();

	int ready = min(ready0, ready1);

	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process <= 0) return false;

	for (auto k = 0; k < process; k++) {

		t_complex_xy valueXY;
		double tetha;

		inputSignals[0]->bufferGet(&valueXY);
		inputSignals[1]->bufferGet(&tetha);
		
		t_complex valueX = valueXY.x;
		t_complex valueY = valueXY.y;

		t_complex valueXout;
		t_complex ValueYout;

		switch (mode) {
		case Sender:
			valueXout = cos(-tetha * PI / 180)*valueX + sin(-tetha * PI / 180)*valueY;
			ValueYout = -sin(-tetha * PI / 180)*valueX + cos(-tetha * PI / 180)*valueY;

			valueXY = { valueXout, ValueYout };
			break;

		case Receiver:
			if(tetha == 0){
				//do nothing
			}
			else {
				valueXout = cos(-tetha * PI / 180)*valueX;
				ValueYout = sin(-tetha * PI / 180)*valueY;
			}
			valueXY = { valueXout, ValueYout };
			break;

		default:
			break;
		}
		

		outputSignals[0]->bufferPut(valueXY);

	}

	return true;
}

