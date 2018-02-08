# include "local_oscillator_20180130.h"

# include <algorithm>
# include <complex>
# include <iostream>
# include <fstream>
# include <random>

using namespace std;


void LocalOscillator::initialize(void) {

	outputSignals[0]->setSamplingPeriod(samplingPeriod);
	outputSignals[0]->setSymbolPeriod(symbolPeriod);

	outputSignals[0]->setCentralWavelength(getWavelength());
	outputSignals[0]->setCentralFrequency(getFrequency());
}


bool LocalOscillator::runBlock(void) {

	int process = outputSignals[0]->space();
	int signalSize = process;

	if (process == 0) return false;

	t_real phNoiseVar, phNoise, randnPhNoiseGen, intNoise, intVar;
	double cm_phNoise (0.0);
	t_complex out(0.0, 0.0);
	double samplingPeriod = outputSignals[0]->getSamplingPeriod();
	const double PI = 3.141592653589793;
	
	normal_distribution<double> dist_phaseNoise(0.0, 1.0);
	normal_distribution<double> dist_RIN(0.0, 1.0);
	
	phNoiseVar = 2 * PI * laserLW * samplingPeriod;
	intVar = (1 / samplingPeriod) * laserRIN * pow(opticalPower, 2);

	for (int i = 0; i < process; i++) {
		randnPhNoiseGen = dist_phaseNoise(generatorPhaseNoise);
		phNoise = sqrt(phNoiseVar)*randnPhNoiseGen;
		cm_phNoise = cm_phNoise + phNoise;

		t_real intNoise = sqrt(intVar)*dist_RIN(generatorRIN);

		out = sqrt(opticalPower + intNoise)*exp(i*(cm_phNoise + phase0));

		outputSignals[0]->bufferPut((t_complex)out);
	}

	return true;
}
