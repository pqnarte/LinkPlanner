# include <algorithm>  // min()
# include <math.h>     // cos(), sin()

# include "netxpto.h"
# include "polarization_beam_splitter.h"

void PolarizationBeamSplitter::initialize(void) {

	outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
	outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
	outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[1]->symbolPeriod = inputSignals[0]->symbolPeriod;
	outputSignals[1]->samplingPeriod = inputSignals[0]->samplingPeriod;
	outputSignals[1]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;
	outputSignals[1]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

}

bool PolarizationBeamSplitter::runBlock(void) {

	int ready = inputSignals[0]->ready();
	int space1 = outputSignals[0]->space();
	int space2 = outputSignals[1]->space();

	int space = min(space1, space2);

	int process = min(ready, space);

	if (process <= 0) return false;

	
	t_complex_xy valueXY;

	for (int k = 0; k <= process; k++) {
		inputSignals[0]->bufferGet(&valueXY);

		t_complex valueX = valueXY.x;
		t_complex valueY = valueXY.y;

		t_complex_xy ValueXout = { valueX * 1.0, valueY * 0.0 };
		t_complex_xy ValueYout = { valueX * 0.0, valueY * 1.0 };

		outputSignals[0]->bufferPut((t_complex_xy)ValueXout);
		outputSignals[1]->bufferPut((t_complex_xy)ValueYout);
	}
	
	

	return true;

};
