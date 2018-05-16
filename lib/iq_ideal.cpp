# include <algorithm>	// std::min

# include "netxpto.h"
# include "iq_ideal.h"


using namespace std;

/* 2016-07-05
IqModulator::IqModulator(vector <Signal *> &InputSig, vector <Signal *> &OutputSig) {

numberOfInputSignals = InputSig.size();
numberOfOutputSignals = OutputSig.size();

inputSignals = InputSig;
outputSignals = OutputSig;


outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

outputSignals[0]->centralWavelength = outputOpticalWavelength;
outputSignals[0]->centralFrequency = outputOpticalFrequency;

}*/

void IqModulator::initialize(void) {

	firstTime = false;

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[0]->centralWavelength = outputOpticalWavelength;
	outputSignals[0]->centralFrequency = outputOpticalFrequency;

}

bool IqModulator::runBlock(void) {

	/*2016-08-03
	if (firstTime) {

	firstTime = false;

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	int aux = inputSignals[0]->getFirstValueToBeSaved();
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[0]->centralWavelength = outputOpticalWavelength;
	outputSignals[0]->centralFrequency = outputOpticalFrequency;

	}
	*/

	int ready0 = inputSignals[0]->ready();
	int ready1 = inputSignals[1]->ready();
	int ready = min(ready0, ready1);

	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process == 0) return false;

	for (int i = 0; i < process; i++) {

		t_complex complexSignal;
		t_complex complexLO;
		t_complex complexOut;
		t_real    realOut;

		inputSignals[0]->bufferGet(&complexSignal);
		inputSignals[1]->bufferGet(&complexLO);

		complexOut = complexSignal*complexLO;
		realOut = complexOut.real();

		outputSignals[0]->bufferPut(realOut);
		
}

	return true;
}


