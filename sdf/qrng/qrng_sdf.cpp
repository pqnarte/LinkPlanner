# include "netxpto.h"

# include "electrical_signal_generator_20180124.h"
# include "clock_20171219.h"
# include "single_photon_source_20171218.h"
# include "polarizer_20180113.h"
# include "polarization_beam_splitter_20180109.h"
# include "single_photon_detector_20180111.h"
# include "qrng_decision_circuit.h"
# include "sink.h"

int main(){

	/*Input Parameters*/

	double RateOfPhotons{ 1e6 };
	int NumberOfSamplesPerSymbol{ 16 };
	vector<t_iqValues> iqAmplitudeValues = { { 0.0,0.0 },{ -45.0,0.0 },{ 90.0,0.0 },{ 337.5,0.0 } };

	// #####################################################################################################
	// ########################### Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	
	TimeContinuousAmplitudeContinuousReal S1{ "S1.sgn" };
	//S1.setSaveSignal(false);

	TimeContinuousAmplitudeContinuousReal S2{ "S2.sgn" };
	//S2.setSaveSignal(false);

	PhotonStreamXY S3{ "S3.sgn" };
	S3.setSaveSignal(false);

	PhotonStreamXY S4{ "S4.sgn" };
	S4.setSaveSignal(false);

	PhotonStreamXYMP S5{ "S5.sgn" };
	S5.setSaveSignal(false);

	TimeContinuousAmplitudeDiscreteReal S6{ "S6.sgn" };
	S6.setSaveSignal(false);

	TimeContinuousAmplitudeDiscreteReal S7{ "S7.sgn" };
	S7.setSaveSignal(false);

	Binary S8{ "S8.sgn" };
	S8.setSaveSignal(false);

	Binary S9{ "S9.sgn" };
	//S9.setSaveSignal(false);

	
	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################
	ElectricalSignalGenerator B1{ vector <Signal*>{}, vector<Signal*>{&S1} };
	B1.setSamplingPeriod((1 / RateOfPhotons));
	B1.setSymbolPeriod(NumberOfSamplesPerSymbol * (1 / RateOfPhotons));
	B1.setFunction(ContinuousWave);
	B1.setGain(45.0);

	Clock B2{ vector<Signal*>{}, vector<Signal*>{&S2} };
	B2.setClockPeriod(1 / RateOfPhotons);
	B2.setSamplingPeriod((1 / RateOfPhotons) / NumberOfSamplesPerSymbol);
	B2.setClockPhase(3 * PI / 2);

	Sink BB4{ vector<Signal*>{&S2}, vector<Signal*>{} };
	BB4.setNumberOfSamples(512);
	Sink BB3{ vector<Signal*>{&S1}, vector<Signal*>{} };
	BB3.setNumberOfSamples(512);
	//B4.setDisplayNumberOfSamples(true);
	/*
	SinglePhotonSource B7{ vector<Signal*>{&S2},vector<Signal*>{&S7} };
	

	Polarizer B8{ vector<Signal*>{&S7, &S6}, vector<Signal*>{&S8} };

	PolarizationBeamSplitter B9{ vector<Signal*>{&S8}, vector<Signal*>{&S9} };

	SinglePhotonDetector B10{ vector<Signal*>{&S9}, vector<Signal*>{&S10} };
	B10.setPath(0);

	SinglePhotonDetector B11{ vector<Signal*>{&S9}, vector<Signal*>{&S11} };
	B11.setPath(1);

	QRNG_DecisionCircuit B12{ vector<Signal*>{&S10,&S11}, vector<Signal*>{&S12} };

	Sink B13{ vector<Signal*>{&S12}, vector<Signal*>{} };
	B13.setNumberOfSamples((long)1e8);
	B13.setDisplayNumberOfSamples(true);*/
	/*
	Sink B14{ vector<Signal*>{&S11}, vector<Signal*>{} };
	B14.setNumberOfSamples((long)10e3);
	B14.setDisplayNumberOfSamples(true);
	*/
	
	
	// #####################################################################################################
	// ########################### System Declaration and Inicialization ###################################
	// #####################################################################################################

	System MainSystem{ vector<Block*> { &B1, &B2, &BB4, &BB3 } };

	// #####################################################################################################
	// #################################### System Run #####################################################
	// #####################################################################################################
	
	MainSystem.run();

	return 0;

}