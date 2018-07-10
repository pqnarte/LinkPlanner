# include "netxpto_20180418.h"

# include "binary_source_20180523.h"
# include "m_qam_mapper_20180118.h"
# include "discrete_to_continuous_time_20180118.h"
# include "pulse_shaper_20180118.h"
# include "iq_modulator_20180130.h"
# include "sink_20180620.h"

// #####################################################################################################
// ################################### System Input Parameters #########################################
// #####################################################################################################

class QPSKInputParameters : public SystemInputParameters {
public:
	//INPUT PARAMETERS
	BinarySourceMode sourceMode{ Random };
	int patternLength{ 5 };
	string bitStream{ "0" };
	double bitPeriod{ 1.0 / 50e9 };
	vector<t_iqValues> iqAmplitudes{ { { 1,1 },{ -1,1 },{ -1,-1 },{ 1,-1 } } };
	int numberOfBits{ 1000 };
	int numberOfSamplesPerSymbol{ 16 };
	double rollOffFactor{ 0.3 };
	int impulseResponseTimeLength{ 16 };
	int bLength{ 16 };

	//METHODS
	//Each parameter must be added to the parameter map by calling addInputParameter(string,param*)
	void initializeInputParameterMap() {
		addInputParameter("patternLength", &patternLength);
		addInputParameter("bitStream", &bitStream);
		addInputParameter("bitPeriod", &bitPeriod);
		addInputParameter("numberOfBits", &numberOfBits);
		addInputParameter("numberOfSamplesPerSymbol", &numberOfSamplesPerSymbol);
		addInputParameter("rollOffFactor", &rollOffFactor);
		addInputParameter("impulseResponseTimeLength", &impulseResponseTimeLength);
		addInputParameter("bLength", &bLength);
	}

	/* Initializes default parameters */
	QPSKInputParameters() : SystemInputParameters() {
		initializeInputParameterMap(); //Initializes the parameters
	}

	/* Initializes input parameters according to the program arguments*/
	QPSKInputParameters(int argc, char*argv[]) : SystemInputParameters(argc, argv) {
		initializeInputParameterMap(); //Initializes the parameters
		readSystemInputParameters();
	}
};

/* Usage: QPSK_Transmitter.exe <input_parameters.txt> <output_directory> */
int main(int argc, char *argv[]) {

	QPSKInputParameters param(argc, argv);

	// #####################################################################################################
	// ########################### Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	
	Binary S1{ "S1.sgn", param.getOutputFolderName() };
	S1.setBufferLength(param.bLength);

	TimeDiscreteAmplitudeDiscreteReal S2{ "S2.sgn", param.getOutputFolderName() };
	S2.setBufferLength(param.bLength);

	TimeDiscreteAmplitudeDiscreteReal S3{ "S3.sgn", param.getOutputFolderName() };
	S3.setBufferLength(param.bLength);

	TimeContinuousAmplitudeDiscreteReal S4{ "S4.sgn", param.getOutputFolderName() };
	S4.setBufferLength(param.bLength);

	TimeContinuousAmplitudeDiscreteReal S5{ "S5.sgn", param.getOutputFolderName() };
	S5.setBufferLength(param.bLength);

	TimeContinuousAmplitudeContinuousReal S6{ "S6.sgn", param.getOutputFolderName() };
	S6.setBufferLength(param.bLength);

	TimeContinuousAmplitudeContinuousReal S7{ "S7.sgn", param.getOutputFolderName() };
	S7.setBufferLength(param.bLength);

	BandpassSignal S8{ "S8.sgn", param.getOutputFolderName() };
	S8.setBufferLength(param.bLength);

	Binary S9{ "S9.sgn", param.getOutputFolderName() };
	S9.setBufferLength(param.bLength);

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################


	BinarySource B1{ vector<Signal*> {}, vector<Signal*> { &S1, &S9 } };
	B1.setMode(param.sourceMode);
	B1.setAsciiFileName("teste.txt");
	B1.setProbabilityOfZero(0.1);
	B1.setPatternLength(param.patternLength);
	B1.setBitStream(param.bitStream);
	B1.setBitPeriod(param.bitPeriod);
	B1.setNumberOfBits(param.numberOfBits);
	
	MQamMapper B2{ vector<Signal*> { &S1 }, vector<Signal*> { &S2, &S3 } };
	B2.setIqAmplitudes(param.iqAmplitudes);

	DiscreteToContinuousTime B3{ vector<Signal*> { &S2 }, vector<Signal*> { &S4 } };
	B3.setNumberOfSamplesPerSymbol(param.numberOfSamplesPerSymbol);
	
	DiscreteToContinuousTime B4{ vector<Signal*> { &S3 }, vector<Signal*> { &S5 } };
	B4.setNumberOfSamplesPerSymbol(param.numberOfSamplesPerSymbol);

	PulseShaper B5{ vector<Signal*> { &S4 }, vector<Signal*> { &S6 } };
	B5.setRollOffFactor(param.rollOffFactor);
	B5.setImpulseResponseTimeLength(param.impulseResponseTimeLength);
	B5.setSeeBeginningOfImpulseResponse(false);

	PulseShaper B6{ vector<Signal*> { &S5 }, vector<Signal*> { &S7 } };
	B6.setRollOffFactor(param.rollOffFactor);
	B6.setImpulseResponseTimeLength(param.impulseResponseTimeLength);
	B6.setSeeBeginningOfImpulseResponse(false);

	IqModulator B7{ vector<Signal*> { &S6, &S7 }, vector<Signal*> { &S8 } };

	Sink B8{ vector<Signal*> { &S8 }, vector<Signal*> {} };
	B8.setDisplayNumberOfSamples(true);

	Sink B9{ vector<Signal*> { &S9 }, vector<Signal*> {} };
	B9.setDisplayNumberOfSamples(true);
	B9.setNumberOfBytesToSaveInFile(6);
	B9.setNumberOfBitsToSkipBeforeSave(0);

	// #####################################################################################################
	// ########################### System Declaration and Inicialization ###################################
	// #####################################################################################################

	System MainSystem{ vector<Block*> { &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8, &B9 },
										param.getOutputFolderName(),
										param.getLoadedInputParameters() };

	// #####################################################################################################
	// #################################### System Run #####################################################
	// #####################################################################################################
	
	MainSystem.run();

	return 0;

}
