# include "single_photon_detector_20180206.h"

void SinglePhotonDetector::initialize(void) {

	numberOfInputSignals = (int)inputSignals.size();
	numberOfOutputSignals = (int)outputSignals.size();

	for (auto k = 0; k < numberOfOutputSignals; k++) {
		outputSignals[k]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
		outputSignals[k]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
		outputSignals[k]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
		outputSignals[k]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
	}
	
}

bool SinglePhotonDetector::runBlock(void) {

	if (numberOfInputSignals > 2) {
		cout << "ERRO: singlephotondetector.cpp (1)" << "\n";
		return false;
	}
	else {
		int ready;
		if (numberOfInputSignals == 1) {
			ready = inputSignals[0]->ready();
		}
		else if (numberOfInputSignals == 2) {
			int ready1 = inputSignals[0]->ready();
			int ready2 = inputSignals[1]->ready();
			ready = min(ready1, ready2);
		}

		int space = outputSignals[0]->space();
		int process = min(ready, space);

		if (process <= 0) return false;

		std::uniform_real_distribution<double> distribution(0.0, 1.0);

		unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count();

		generator.seed(seed);

		signal_value_type inSignalType = inputSignals[0]->getValueType();

		for (auto k = 0; k < process; k++) {
			t_real clk;
			if (numberOfOutputSignals > 1) 
				inputSignals[1]->bufferGet(&clk);
			else 
				clk = 1.0;
			

			t_photon_mp_xy inValueMP;
			inputSignals[0]->bufferGet(&inValueMP);

			t_complex_xy inValue = (t_complex_xy)inValueMP.path[path];
			t_complex xValue = inValue.x;
			t_complex yValue = inValue.y;

			switch (path) {
			case 0:
				if ((abs(xValue) >= 0.0) && (abs(xValue) <= 1.0) && (clk > 0.0)) {
					double number = distribution(generator);
					if (number < (pow(abs(xValue), 2) + probabilityDarkCount)) {
						outputSignals[0]->bufferPut((t_real)1.0);
						inValueMP.path[1].x = (t_complex) 0.0;
						inValueMP.path[1].y = (t_complex) 0.0;
					}
					else {
						outputSignals[0]->bufferPut((t_real)0.0);
						inValueMP.path[1].x = (t_complex) 0.0;
						inValueMP.path[1].y = (t_complex) 1.0;
					}
				}

				break;

			case 1:
				if (clk > 0.0){
					if (abs(yValue) == 1.0)
						outputSignals[0]->bufferPut((t_real)1.0);
					else {
						double number = distribution(generator);
						if (number < probabilityDarkCount) {
							outputSignals[0]->bufferPut((t_real)1.0);
						}
						else
							outputSignals[0]->bufferPut((t_real)0.0);
					}
				}
				break;

			default:
				cout << "x:" << abs(xValue) << "y:" << abs(yValue) << "\n";
				break;

			}

			if ((abs(inValueMP.path[1].y) == 0.0) || (abs(inValueMP.path[1].y) == 1.0) && (clk > 0.0)) {
				inputSignals[0]->bufferPut((t_photon_mp_xy)inValueMP);
			}
		}

	}

	return true;
};
