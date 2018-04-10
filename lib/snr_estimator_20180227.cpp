// Currently mostly copied from BER
#include <algorithm>
#include <complex>

#include "netxpto_20180118.h"
#include "snr_estimator_20180227.h"

void SNREstimator::initialize(void) {
	firstTime = false;

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}

bool SNREstimator::runBlock(void) {

	
	return true;
}

