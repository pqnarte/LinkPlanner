#ifndef BOB_QKD_H_
#define BOB_QKD_H

#include "netxpto.h"
#include "binary_mapper.h"
#include "discrete_to_continuous_time.h"
#include "pulse_shaper.h"
#include "super_block_interface.h"

class BobQKD : public SuperBlock {

	// #####################################################################################################
	// ################## Internal Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	TimeDiscreteAmplitudeDiscreteReal S1{ "Bob_1.sgn" };
	TimeContinuousAmplitudeDiscreteReal S2{ "Bob_2.sgn" };
	TimeContinuousAmplitudeDiscreteReal S3{ "S44.sgn" };

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################
	BinaryMapper BB0;
	DiscreteToContinuousTime BB1;
	PulseShaper BB2;

	SuperBlockInterface BB9;


public:
	/* input parameters*/


	BobQKD(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals);

	void setNumberOfSamplesPerSymbol(int n) { BB1.setNumberOfSamplesPerSymbol(n); };
	int const getNumberOfSamplesPerSymbol(void) { return BB1.getNumberOfSamplesPerSymbol(); };

	void setSeeBeginningOfImpulseResponse(bool sBeginningOfImpulseResponse) { BB2.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); };
	double const getSeeBeginningOfImpulseResponse(void) { return BB2.getSeeBeginningOfImpulseResponse(); };

	void setPulseShaperFilter(PulseShaperFilter fType) { BB2.setFilterType(fType); };

};

#endif
