# include <algorithm>  // min

# include "netxpto.h"
# include "single_photon_source.h"

void SinglePhotonSource::initialize(void) {

	inputSignalValueType = inputSignals[0]->getValueType();

	outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
	outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
	outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

}

bool SinglePhotonSource::runBlock(void) {

	int ready, space, length;

	ready = inputSignals[0]->ready();
	space = outputSignals[0]->space();

	length = min(ready, space);

	if (length <= 0) return false;

	t_real re;

	for (int i = 0; i < length; i++) {
		inputSignals[0]->bufferGet(&re);
		t_complex valueX(re, 0);
		t_complex valueY(0, 0);

		t_complex_xy valueXY = { valueX, valueY };

		outputSignals[0]->bufferPut(valueXY);
		
	}
			
	return true;

};
