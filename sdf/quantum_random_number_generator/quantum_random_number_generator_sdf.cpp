# include "netxpto_20180118.h"

# include "electrical_signal_generator_20180124.h"
# include "clock_20171219.h"
# include "single_photon_source_20171218.h"
# include "polarizer_20180113.h"
# include "polarization_beam_splitter_20180109.h"
# include "probability_estimator_20180124.h"
# include "single_photon_detector_20180111.h"
# include "qrng_decision_circuit.h"
# include "sink_20180118.h"

int main(){

	// #####################################################################################################
	// ################################### System Input Parameters #########################################
	// #####################################################################################################

	double rateOfPhotons{ 1e6 };
	double polarizerAngle{ 360.0 };

	QRNGParameters* param = new QRNGParameters(rateOfPhotons, polarizerAngle);

	// #####################################################################################################
	// ################################### Simulation Parameters ###########################################
	// #####################################################################################################

	int numberOfSamplesPerSymbol{ 16 };

	// #####################################################################################################
	// ########################### Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	
	TimeContinuousAmplitudeContinuousReal S1{ "S1.sgn" };
	S1.setSaveSignal(false);

	TimeContinuousAmplitudeContinuousReal S2{ "S2.sgn" };
	S2.setSaveSignal(false);

	PhotonStreamXY S3{ "S3.sgn" };
	S3.setSaveSignal(false);

	PhotonStreamXY S4{ "S4.sgn" };
	S4.setSaveSignal(false);

	PhotonStreamMPXY S5{ "S5.sgn" };
	S5.setSaveSignal(false);

	TimeContinuousAmplitudeContinuousReal S6{ "S6.sgn" };
	S6.setSaveSignal(false);

	TimeContinuousAmplitudeContinuousReal S7{ "S7.sgn" };
	S7.setSaveSignal(false);

	Binary S8{ "S8.sgn" };
	S8.setSaveSignal(false);

	Binary S9{ "S9.sgn" };
	S9.setSaveSignal(false);

	
	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################
	ElectricalSignalGenerator B1{ vector <Signal*>{}, vector<Signal*>{&S1} };
	B1.setSamplingPeriod((1 / param->rateOfPhotons) / numberOfSamplesPerSymbol);
	B1.setSymbolPeriod(numberOfSamplesPerSymbol * (1 / param->rateOfPhotons));
	B1.setFunction(ContinuousWave);
	B1.setGain(param->polarizerAngle);

	Clock B2{ vector<Signal*>{}, vector<Signal*>{&S2} };
	B2.setClockPeriod(1 / param->rateOfPhotons);
	B2.setSamplingPeriod((1 / param->rateOfPhotons) / numberOfSamplesPerSymbol);
	B2.setClockPhase(3 * PI / 2);
	
	SinglePhotonSource B3{ vector<Signal*>{&S2},vector<Signal*>{&S3} };
	
	Polarizer B4{ vector<Signal*>{&S3, &S1}, vector<Signal*>{&S4} };

	PolarizationBeamSplitter B5{ vector<Signal*>{&S4}, vector<Signal*>{&S5} };

	SinglePhotonDetector B6{ vector<Signal*>{&S5}, vector<Signal*>{&S6} };
	B6.setPath(0);

	SinglePhotonDetector B7{ vector<Signal*>{&S5}, vector<Signal*>{&S7} };
	B7.setPath(1);

	QRNG_DecisionCircuit B8{ vector<Signal*>{&S6,&S7}, vector<Signal*>{&S8} };

	ProbabilityEstimator B9{ vector<Signal*>{&S8}, vector<Signal*>{&S9} };
	B9.setFileName("360degrees.txt");

	Sink B10{ vector<Signal*>{&S9}, vector<Signal*>{} };
	B10.setNumberOfSamples((long)1e6);
	B10.setDisplayNumberOfSamples(true);
	
	
	
	// #####################################################################################################
	// ########################### System Declaration and Inicialization ###################################
	// #####################################################################################################

	System MainSystem{ vector<Block*> { &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8, &B9, &B10 } };

	// #####################################################################################################
	// #################################### System Run #####################################################
	// #####################################################################################################
	
	MainSystem.run();

	return 0;

}