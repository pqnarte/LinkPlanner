# include "probability_estimator_20180124.h"

void ProbabilityEstimator::initialize(void) {

	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}

bool ProbabilityEstimator::runBlock(void) {

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	/*Outputing file*/
	if ((process == 0) && (firstTime != 1)) {

		double ProbabilityOf1 = (double)(NumberOf1 / receivedData) * 100;
		double ProbabilityOf0 = (double)(NumberOf0 / receivedData) * 100;

		/*Outputing a .txt report*/
		ofstream myfile;
		myfile.open("QRNG.txt");
		myfile << "Number of received Bits: " << receivedData << "\n";
		myfile << "Probability Of 0: " << ProbabilityOf0 << "% \n";
		myfile << "Probability Of 1: " << ProbabilityOf1 << "% \n";


		return false;
	}

	if (firstTime == 1) firstTime = 0;
	

	for (auto i = 0; i < process; i++) {
		t_binary inValue;

		inputSignals[0]->bufferGet(&inValue);

		if (inValue == 0) {
			NumberOf0 = NumberOf0 + 1;
			receivedData++;
		}
		if (inValue == 1) {
			NumberOf1 = NumberOf1 + 1;
			receivedData++;
		}

		outputSignals[0]->bufferPut((t_binary)inValue);

	}


	return true;
}