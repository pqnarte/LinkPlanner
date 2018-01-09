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

	int length = min(ready, space);

	if (length <= 0) return false;

	signal_value_type inSignalType = inputSignals[0]->getValueType();

	if (inSignalType == ComplexValueXY) {
		t_complex_xy valueXY;

		for (int i = 0; i <= length; i++) {
			inputSignals[0]->bufferGet(&valueXY);

			t_complex valueXX = valueXY.x;
			t_complex valueYY = valueXY.y;
			t_complex valueXY = 0.0;
			t_complex valueYX = 0.0;

			t_complex_xy ValueXout = { valueXX, valueXY };
			t_complex_xy ValueYout = { valueYX, valueYY };

			outputSignals[0]->bufferPut((t_complex_xy)ValueXout);
			outputSignals[1]->bufferPut((t_complex_xy)ValueYout);
		}
	}
	else {
		
	}
	

	return true;

};
