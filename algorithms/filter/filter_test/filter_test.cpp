# include "netxpto.h"
# include "binary_source.h"
# include "m_qam_mapper.h"	
# include "discrete_to_continuous_time.h"
# include "sink.h"
# include "filter.h"
# include "fork.h"

int main() {

	// #######################################################################
	// ###################### System Input Parameters ########################
	// #######################################################################

	BinarySourceMode sourceMode{ PseudoRandom };
	int patternLength{ 5 };
	double bitPeriod{ 1.0 / 1.25e9 };
	vector<t_iqValues> iqAmplitudes{ { { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } } };
	int numberOfBits{ 1000 };		  // -1 will generate long bit sequence.
	int numberOfSamplesPerSymbol{ 8 };
	double rollOffFactor{ 0.3 };
	int impulseResponseTimeLength{ 32 };
	
	// ########################################################################
	// ################ Signals Declaration and Inicialization ################
	// ########################################################################

	Binary S1{ "S1.sgn" };							 // Binary Sequence
	TimeDiscreteAmplitudeDiscreteReal S2{"S2.sgn"};	 // MPAM Signal
	TimeDiscreteAmplitudeDiscreteReal S2b{"S2b.sgn"};// Not used (Q signal)
	TimeContinuousAmplitudeDiscreteReal S3{"S3.sgn"};// Discrete to continious time
	TimeContinuousAmplitudeContinuousReal S4{"S4.sgn"};// Pulse Shapping filter
	TimeContinuousAmplitudeContinuousReal S5{"S5.sgn"};// Hilbert filter
	TimeContinuousAmplitudeContinuousReal S6{"S6.sgn"};
	TimeContinuousAmplitudeContinuousReal S7{"S7.sgn"};

	// #########################################################################
	// ############### Blocks Declaration and Inicialization ###################
	// #########################################################################

	BinarySource B1{ vector<Signal*> {}, vector<Signal*> { &S1} };
	B1.setMode(sourceMode);
	B1.setPatternLength(patternLength);
	B1.setBitPeriod(bitPeriod);
	B1.setNumberOfBits(numberOfBits);

	MQamMapper B2{ vector<Signal*> { &S1 }, vector<Signal*> { &S2, &S2b } };
	B2.setIqAmplitudes(iqAmplitudes);

	Sink B3{ vector<Signal*> { &S2b }, vector<Signal*> {} };

	DiscreteToContinuousTime B4{ vector<Signal*> { &S2 }, vector<Signal*> { &S3 } };
	B4.setNumberOfSamplesPerSymbol(numberOfSamplesPerSymbol);

	Fork B5{ vector<Signal*> { &S3 }, vector<Signal*> { &S4, &S5 } };

	PulseShaper B6{ vector<Signal*> { &S4 }, vector<Signal*> { &S6 } };
	B6.setRollOffFactor( rollOffFactor);
	B6.setImpulseResponseTimeLength(impulseResponseTimeLength);
	B6.setSeeBeginningOfImpulseResponse(false);
	B6.setFilterDomainType("time");
	B6.setFilterType(RaisedCosine);

	PulseShaper B7{ vector<Signal*> { &S5 }, vector<Signal*> { &S7 } };
	B7.setRollOffFactor(rollOffFactor);
	B7.setImpulseResponseTimeLength(impulseResponseTimeLength);
	B7.setSeeBeginningOfImpulseResponse(false);
	B7.setFilterDomainType("frequency");
	B7.setFilterType(RaisedCosine);

	Sink B8{ vector<Signal*> { &S6 }, vector<Signal*> {} };
	Sink B9{ vector<Signal*> { &S7 }, vector<Signal*> {} };



	// ############################################################################
	// ################ System Declaration and Inicialization #####################
	// ############################################################################

	System MainSystem{ vector<Block*> { &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8, &B9	\} };

	// ############################################################################
	// ############################# System Run ###################################
	// ############################################################################

	MainSystem.run();
	cout << "\nExecution Finished, Please hit Enter to exit!";
	getchar();
	return 0;
}