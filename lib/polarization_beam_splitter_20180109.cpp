# include "polarization_beam_splitter_20180109.h"

# include <algorithm>  // min()
# include <math.h>     // cos(), sin()

<<<<<<< HEAD
# include "netxpto.h"
# include "polarization_beam_splitter.h"

=======
>>>>>>> Develop.Mariana_TQ
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

<<<<<<< HEAD
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
		
=======
		t_complex_xy inSignal1;
		t_photon_mp_xy outSignal1;
		//This should implement a 1x2 beam splitters

		inputSignals[0]->bufferGet(&inSignal1);

		t_complex xValueH = (inSignal1.x * matrixH[0] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2)))) + (inSignal1.y * matrixH[1] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2))));
		t_complex yValueH = (inSignal1.x * matrixH[2] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2)))) + (inSignal1.y * matrixH[3] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2))));

		t_complex xValueV = (inSignal1.x * matrixV[0] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2)))) + (inSignal1.y * matrixV[1] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2))));
		t_complex yValueV = (inSignal1.x * matrixV[2] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2)))) + (inSignal1.y * matrixV[3] * (1 / sqrt(pow(abs(inSignal1.x), 2) + pow(abs(inSignal1.y), 2))));

		outSignal1.path[0] = { xValueH, yValueH };

		outSignal1.path[1] = { xValueV, yValueV };


		outputSignals[0]->bufferPut((t_photon_mp_xy)outSignal1);
>>>>>>> Develop.Mariana_TQ
	}
	

	return true;

};
