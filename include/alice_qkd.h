#ifndef ALICE_QKD_H_
#define ALICE_QKD_H

#include "netxpto.h"
#include "binary_source.h"
#include "m_qam_mapper.h"
#include "discrete_to_continuous_time.h"
#include "pulse_shaper.h"
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

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################
	BinarySource B1;

	MQamMapper B2;

	DiscreteToContinuousTime B3;

	PulseShaper B4;

	Sink B5;

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

	void setRateOfPhotons(double RPhotons) { RateOfPhotons = RPhotons; };
	double const getRateOfPhotons(void) { return RateOfPhotons; };

	void setStringPhotonsLength(int pLength) { StringPhotonsLength = pLength; };
	int const getStringPhotonsLength(void) { return StringPhotonsLength; };

	void setM(int mValue) { B2.m = mValue; };
	int const getM(void) { return B2.m; };

	void setIqAmplitudes(vector<t_iqValues> iqAmplitudesValues) { B2.m = iqAmplitudesValues.size(); B2.iqAmplitudes.resize(B1.m); B2.iqAmplitudes = iqAmplitudesValues; };
	vector<t_iqValues> const getIqAmplitudes(void) { return B2.iqAmplitudes; };

	void setNumberOfSamplesPerSymbol(int n) { B3.setNumberOfSamplesPerSymbol(n); };
	int const getNumberOfSamplesPerSymbol(void) { return B3.getNumberOfSamplesPerSymbol(); };

	void setRollOffFactor(double rOffFactor) { B5.setRollOffFactor(rOffFactor); };
	double const getRollOffFactor(void) { return B5.getRollOffFactor(); };

	void setSeeBeginningOfImpulseResponse(bool sBeginningOfImpulseResponse) { B5.setSeeBeginningOfImpulseResponse(sBeginningOfImpulseResponse); };
	double const getSeeBeginningOfImpulseResponse(void) { return B5.getSeeBeginningOfImpulseResponse(); };

	void setPulseShaperFilter(PulseShaperFilter fType) { B5.setFilterType(fType); };

};

#endif
