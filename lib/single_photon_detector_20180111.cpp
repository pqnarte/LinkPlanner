# include <algorithm>  // min()
# include <random>
# include <math.h>	   // remainder(), pow()

# include "netxpto.h"
# include "single_photon_detector_20180111.h"

void SinglePhotonDetector::initialize(void) {

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

}

bool SinglePhotonDetector::runBlock(void) {

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process <= 0) return false;


	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0.0, 1.0);

	signal_value_type inSignalType = inputSignals[0]->getValueType();
	switch (inSignalType) {
		case PhotonValue:
			for (auto k = 0; k < process; k++) {
				t_photon inValue;
				inputSignals[0]->bufferGet(&inValue);
				if (inValue.probabilityAmplitude == 1) {
					outputSignals[0]->bufferPut((t_real) 1.0);
				}
				else {
					outputSignals[0]->bufferPut((t_real) 0.0);
				}
			}
			break;
		case PhotonValueMP:
			for (auto k = 0; k < process; k++) {
				t_photon_mp inValueMP;
				inputSignals[0]->bufferGet(&inValueMP);
				if (inValueMP.path[path].probabilityAmplitude > 0.0) {	// Process Photon Path
					double number = distribution(generator);
					if (number < pow(inValueMP.path[path].probabilityAmplitude, 2)) {
						outputSignals[0]->bufferPut((t_real) 1.0);
						inValueMP.path[(path + 1) % 2].probabilityAmplitude = 0.0;
						inValueMP.path[path].probabilityAmplitude = -1.0; // Photon Path Processed
					}
					else {
						outputSignals[0]->bufferPut((t_real) 0.0);
						inValueMP.path[(path + 1) % 2].probabilityAmplitude = 1.0;
						inValueMP.path[path].probabilityAmplitude = -1.0; // Photon Path Processed
					}
				};
				if (inValueMP.path[path].probabilityAmplitude == 0.0) {
					outputSignals[0]->bufferPut((t_real) 0.0);
					inValueMP.path[path].probabilityAmplitude = -1.0; // Photon Path Processed
				}
				if (inValueMP.path[(path + 1) % 2].probabilityAmplitude >= 0.0) {
						inputSignals[0]->bufferPut((t_photon_mp)inValueMP);
				}
			}
			break;

		case ComplexValueXYMP:
			for (auto k = 0; k < process; k++) {
				t_complex_xy_mp inValueMP;
				inputSignals[0]->bufferGet(&inValueMP);

				if ((path == Horizontal) && (abs(inValueMP.path[Horizontal].x) == 1.0))
				{
					outputSignals[0]->bufferPut((t_real) 1.0);
					inValueMP.path[(path + 1) % 2].x = (t_complex) 0.0;
				}
				if ((path == Vertical) && (abs(inValueMP.path[Vertical].y) == 1.0))
				{
					outputSignals[0]->bufferPut((t_real) 1.0);
					inValueMP.path[(path + 1) % 2].y = (t_complex) 0.0;
				}
				if ((abs(inValueMP.path[path].x) == abs(inValueMP.path[path].y)) && (abs(inValueMP.path[path].x) != 0.0))
				{
					double number = distribution(generator);
					if (number < pow(abs(inValueMP.path[path].x), 2)) {
						outputSignals[0]->bufferPut((t_real) 1.0);
						inValueMP.path[(path + 1) % 2].x = (t_complex) 0.0;
						inValueMP.path[(path + 1) % 2].y = (t_complex)  0.0;
					}
					else {
						outputSignals[0]->bufferPut((t_real) 0.0);
						if (path == Horizontal) {
							inValueMP.path[(path + 1) % 2].y = (t_complex) 1.0;
							inValueMP.path[(path + 1) % 2].x = (t_complex) 0.0;
						}
						else {
							inValueMP.path[(path + 1) % 2].y = (t_complex) 0.0;
							inValueMP.path[(path + 1) % 2].x = (t_complex) 1.0;
						}
					}
				}
				
				else {
					outputSignals[0]->bufferPut((t_real) 0.0);
				}

				if ((abs(inValueMP.path[(path + 1) % 2].x) >= 0.0) || (abs(inValueMP.path[(path + 1) % 2].y) >= 0.0)) {
					inputSignals[0]->bufferPut((t_complex_xy_mp)inValueMP);
				}
			}
			break;
		default:
			cout << "ERRO: single_photon_detector.cpp" << "\n";
			return false;
	};

	return true;
};
