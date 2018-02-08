#ifndef BOB_QKD_H_
#define BOB_QKD_H

#include "netxpto_20180118.h"
#include "binary_mapper_20180205.h"
#include "discrete_to_continuous_time_20180118.h"
#include "pulse_shaper_20180111.h"
#include "super_block_interface_20180118.h"
#include "fork_20180112.h"
#include "detection_decision_circuit_20180206.h"
#include "sink.h"


class BobQKD : public SuperBlock {

	// #####################################################################################################
	// ################## Internal Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	TimeDiscreteAmplitudeDiscreteReal Bob_1{ };
	TimeContinuousAmplitudeDiscreteReal Bob_2{ };
	TimeContinuousAmplitudeDiscreteReal S4_B{ };
	TimeContinuousAmplitudeDiscreteReal S4{ };
	TimeContinuousAmplitudeDiscreteReal Bob_3{ };
	TimeContinuousAmplitudeDiscreteReal CLKB_1{ };
	TimeContinuousAmplitudeDiscreteReal CLKB_2{ };
	TimeContinuousAmplitudeDiscreteReal CLKB_out1{ };
	TimeContinuousAmplitudeDiscreteReal CLKB_out2{ };

	Binary Bob_7{"Bob_7.sgn"};
	

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################
	BinaryMapper BB0;
	DiscreteToContinuousTime BB1;
	PulseShaper BB2;

	PulseShaper BB3;
	Fork BB4;

	SuperBlockInterface BB9;

	DetectionDecisionCircuit BB10;
	Sink BBSink;

public:
	/* input parameters*/


	BobQKD(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals);

	void setNumberOfSamplesPerSymbol(int n) { BB1.setNumberOfSamplesPerSymbol(n); };
	int const getNumberOfSamplesPerSymbol(void) { return BB1.getNumberOfSamplesPerSymbol(); };

	void setSeeBeginningOfImpulseResponse(bool sBeginningOfImpulseResponse) { BB2.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); };
	double const getSeeBeginningOfImpulseResponse(void) { return BB2.getSeeBeginningOfImpulseResponse(); };

	void setPulseShaperFilter(PulseShaperFilter fType) { BB2.setFilterType(fType); BB3.setFilterType(fType); };

	void setPulseWidth(double tWidth) { BB3.setPulseWidth(tWidth); };
	double getPulseWidth() { return BB3.getPulseWidth(); };

	void setPulseDelay(double pDelay) { BB3.setPulseDelay(pDelay); };
	double getPulseDelay() { return BB3.getPulseDelay(); };

};

#endif
