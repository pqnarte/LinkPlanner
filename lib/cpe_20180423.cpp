# include "cpe_20180423.h"

# include <algorithm>
# include <complex>
# include <iostream>
# include <fstream>
# include <random>
#include <math.h>

//# include "netxpto_20180118.h"
using namespace std;

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif


void CPE::initialize(void) {

	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	//outputSignals[0]->setSymbolPeriod(symbolPeriod);
	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	//outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}


bool CPE::runBlock(void) {

	UnwrapFunctions UnWrapClass;

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process == 0) return false;
	
	const complex<double> I(0, 1);
	//t_complex aux(0.0, 0.0);

	if (!methodType.compare("VV")) {

		t_complex var(0.0, 0.0);
		vector<complex <double>> bufferInput(process + nTaps - 1);
		vector<complex <double>> bufferOutput(process);
		vector <double> phaseEstimation(process);

		for (int i = 0; i < process; i++) {

			inputSignals[0]->bufferGet(&var);
			bufferInput.at((nTaps-1)/2 + i) = pow(var, 4);
		}

		for (int i = 0; i < process; ++i) {
			t_complex aux(0.0, 0.0);
			for (int k = 0; k < nTaps; ++k) {

				aux = aux + bufferInput.at(i + k);
			}
			aux = aux / double(nTaps);
			phaseEstimation.at(i) = atan2(imag(aux) , real(aux));
		}

		UnWrapClass.Unwrap(phaseEstimation);

		for (int i = 0; i < process; ++i) {

			inputSignals[0]->bufferGet(&var);
			bufferOutput.at(i) = var * exp(-I * (phaseEstimation.at(i) / 4 - M_PI/4));
		}
		for (int i = 0; i < process; i++) {

			outputSignals[0]->bufferPut(bufferOutput.at(i));

		}
		return true;
	}
	if (!methodType.compare("BPS")) {

		DecisionCircuitQPSK DC;

		t_complex var(0.0, 0.0);
		t_complex Signal_rot(0.0, 0.0);
		t_complex Signal_ref(0.0, 0.0);
		vector <double> vect_temp(process + nTaps - 1, 0);
		vector<vector <double>> bufferABSdiff(nTestPhase, vect_temp);
		vector<vector <double>> phaseEstimationBPS(nTestPhase, vect_temp);
		vector<complex <double>> bufferOutput(process);
		vector <double> phaseEstimation(process);
		vector <int> index_phaseTest(process);
		vector<complex <double>> InputRotated(process);
		vector <double> phiTestSel(process);
		t_real phiTest = 0;		

		for (int b = 0; b < nTestPhase; b++) {

			phiTest = (double(b) / double(nTestPhase) - 1.0 / 2.0) * phiInt;

			for (int i = 0; i < process; i++) {

				inputSignals[0]->bufferGet(&var);
				Signal_rot = var * exp(I * phiTest);
				Signal_ref = DC.DecisionCircuit(Signal_rot);			
				bufferABSdiff[b][(nTaps - 1) / 2 + i] = pow(abs(Signal_rot - Signal_ref), 2);
			}						
		}

		for (int b = 0; b < nTestPhase; b++) {

			for (int i = 0; i < process; ++i) {

				double aux(0.0);
				for (int k = 0; k < nTaps; ++k) {

					aux = aux + bufferABSdiff[b][i + k];
				}
				aux = aux / double(nTaps);
				phaseEstimationBPS[b][i] = aux;
								
			}
		}

		for (int i = 0; i < process; ++i) {

			double aux = 1000.0;
			index_phaseTest.at(i) = -1;
			
			for (int b = 0; b < nTestPhase; b++) {
				if (phaseEstimationBPS[b][i] >= 0.0 && phaseEstimationBPS[b][i] < aux ) {
					aux = phaseEstimationBPS[b][i];
					index_phaseTest.at(i) = b;
				}
			}
			phiTestSel.at(i) = (double(index_phaseTest.at(i)) / double(nTestPhase) - 1.0 / 2.0) * phiInt;
		}
		UnWrapClass.Unwrap(phiTestSel);
		
		for (int i = 0; i < process; i++) {

			inputSignals[0]->bufferGet(&var);
			bufferOutput.at(i) = var * exp(I * (phiTestSel.at(i) )); 
			outputSignals[0]->bufferPut(bufferOutput.at(i));
		}
		return true;
	}
	cout << "ERROR: Undefined CPE method \n";
	return false;
		
}
