#ifndef ALICE_QKD_H_
#define ALICE_QKD_H

#include "netxpto.h"
#include "binary_source.h"
#include "m_qam_mapper.h"
#include "discrete_to_continuous_time.h"
#include "pulse_shaper.h"
#include "clock.h"
#include "sink.h"

class AliceQKD : public SuperBlock {
	/* State Variables */

	// #####################################################################################################
	// ################## Internal Signals Declaration and Inicialization ##################################
	// #####################################################################################################

	Binary S1{ "NUM_A.sgn" };

	TimeDiscreteAmplitudeDiscreteReal S2{ "MQAM_I.sgn" };

	TimeDiscreteAmplitudeDiscreteReal S3{ "MQAM_Q.sgn" };

	TimeContinuousAmplitudeDiscreteReal S4{ "S4.sgn" };

	TimeContinuousAmplitudeContinuousReal S5{ "S5.sgn" };

	TimeContinuousAmplitudeContinuousReal CLK_A{ "CLK_A.sgn" };

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################

	BinarySource B1;

	MQamMapper B2;

	DiscreteToContinuousTime B3;

	PulseShaper B4;

	Sink B5{ vector<Signal*>{&S3}, vector<Signal*>{} };

	Clock B6;



public:
	/* input parameters*/

	double RateOfPhotons{1e3};
	int StringPhotonsLength{ 12 };

	// Methods
	AliceQKD (vector <Signal*> &inputSignals, vector <Signal*> &outputSignals);

	// Set methods
	void set(int opt);

	void setMode(BinarySourceMode m) { B1.setMode(m); };
	BinarySourceMode const getMode(void) { return B1.getMode(); };

	void setProbabilityOfZero(double pZero) { B1.setProbabilityOfZero(pZero); };
	double const getProbabilityOfZero(void) { return B1.getProbabilityOfZero(); };

	void setBitStream(string bStream) { B1.setBitStream(bStream); };
	string const getBitStream(void) { return B1.getBitStream(); };

	void setNumberOfBits(long int nOfBits) { B1.setNumberOfBits(nOfBits); }
	long int const getNumberOfBits(void) { return B1.getNumberOfBits(); }

	void setPatternLength(int pLength) { B1.setPatternLength(pLength); }
	int const getPatternLength(void) { return B1.getPatternLength(); }

	void setBitPeriod(double bPeriod) { B1.setBitPeriod(bPeriod); };
	double const getBitPeriod(void) { return B1.getBitPeriod(); }

	void setM(int mValue) { B2.m = mValue; };
	int const getM(void) { return B2.m; };

	void setIqAmplitudes(vector<t_iqValues> iqAmplitudesValues) { B2.m = iqAmplitudesValues.size(); B2.iqAmplitudes.resize(B2.m); B2.iqAmplitudes = iqAmplitudesValues; };
	vector<t_iqValues> const getIqAmplitudes(void) { return B2.iqAmplitudes; };

	void setNumberOfSamplesPerSymbol(int n) { B3.setNumberOfSamplesPerSymbol(n); };
	int const getNumberOfSamplesPerSymbol(void) { return B3.getNumberOfSamplesPerSymbol(); };

	void setRollOffFactor(double rOffFactor) { B4.setRollOffFactor(rOffFactor); };
	double const getRollOffFactor(void) { return B4.getRollOffFactor(); };

	void setSeeBeginningOfImpulseResponse(bool sBeginningOfImpulseResponse) { B4.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); };
	double const getSeeBeginningOfImpulseResponse(void) { return B4.getSeeBeginningOfImpulseResponse(); };

	void setPulseShaperFilter(PulseShaperFilter fType) { B4.setFilterType(fType); };

	void setNumberOfSamples(long int nOfSamples) { B5.setNumberOfSamples(nOfSamples); };

	void setDisplayNumberOfSamples(bool opt) { B5.setDisplayNumberOfSamples(opt); };

	void setClockPeriod(double per) { B6.setClockPeriod(per); };

	void setSamplingPeriod(double speriod) { B6.setSamplingPeriod(speriod); };
	
};

#endif
