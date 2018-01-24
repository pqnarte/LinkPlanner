# include <algorithm>  // min()
# include <math.h>     // cos(), sin()

# include "netxpto.h"
# include "polarization_beam_splitter_20180109.h"

void PolarizationBeamSplitter::initialize(void) {

	firstTime = false;

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());


}

bool PolarizationBeamSplitter::runBlock(void) {

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process <= 0) return false;

	for (auto i = 0; i < process; i++) {

		t_complex_xy inSignal1;
		t_complex_xy_mp outSignal1;
		//This should implement a 1x2 beam splitters

		inputSignals[0]->bufferGet(&inSignal1);
		
		t_complex xValue = inSignal1.x * matrix[0] + inSignal1.y * matrix[1];
		t_complex yValue = inSignal1.x * matrix[2] + inSignal1.y * matrix[3];

		outSignal1.path[0].x = xValue;
		outSignal1.path[0].y = yValue;

		outSignal1.path[1].x = xValue;
		outSignal1.path[1].y = yValue;

		outputSignals[0]->bufferPut((t_complex_xy_mp)outSignal1);
	}
	
	return true;

};
