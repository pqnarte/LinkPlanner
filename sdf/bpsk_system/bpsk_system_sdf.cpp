# include "netxpto.h"

# include "m_qam_transmitter.h"
# include "homodyne_receiver.h"
# include "bit_error_rate.h"
# include "sink.h"

int main(){

	// #####################################################################################################
	// #################################### System Input Parameters ########################################
	// #####################################################################################################

	t_integer numberOfBitsReceived(-1);
	t_integer numberOfBitsGenerated(50);
	t_integer samplesPerSymbol(16);
	t_integer pLength = 5;
	t_real bitPeriod = 1.0 / 50e9;
	t_real rollOffFactor = 0.3;
	vector<t_iqValues> iqAmplitudeValues = { { 1, 0 }, { -1, 0 } };
	t_real signalOutputPower_dBm = -20;
	t_real localOscillatorPower_dBm = -10;
	t_real localOscillatorPhase = 0;
	array<t_complex, 4> transferMatrix = { { 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), -1 / sqrt(2)} };
	t_real responsivity = 1;
	t_real amplification = 10e6;
	t_real noiseAmplitude = 1e-16;
	t_integer delay = 9;
	t_real confidence = 0.95;
	t_integer midReportSize = 0;
	t_integer bufferLength = 256;
	
	
	// #####################################################################################################
	// ########################### Signals Declaration and Inicialization ##################################
	// #####################################################################################################

	Binary S0{ "S0.sgn" };
	S0.setBufferLength(bufferLength);

	OpticalSignal S1("S1.sgn");
	S1.setBufferLength(bufferLength);

	Binary S2{ "S2.sgn" };
	S2.setBufferLength(bufferLength);

	Binary S3{ "S3.sgn" };
	S3.setBufferLength(bufferLength);

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################

	MQamTransmitter B1{ vector<Signal*> { }, vector<Signal*> { &S1, &S0 } };
	B1.setNumberOfBits(numberOfBitsGenerated);
	B1.setOutputOpticalPower_dBm(signalOutputPower_dBm);
	B1.setMode(PseudoRandom);
	B1.setBitPeriod(bitPeriod);
	B1.setPatternLength(pLength);
	B1.setIqAmplitudes(iqAmplitudeValues);
	B1.setNumberOfSamplesPerSymbol(samplesPerSymbol);
	B1.setRollOffFactor(rollOffFactor);
	B1.setSaveInternalSignals(false);

	HomodyneReceiver B2{ vector<Signal*> {&S1}, vector<Signal*> {&S2} };
	B2.setLocalOscillatorOpticalPower_dBm(localOscillatorPower_dBm);
	B2.setLocalOscillatorPhase(localOscillatorPhase);
	B2.setTransferMatrix(transferMatrix);
	B2.setResponsivity(responsivity);
	B2.setAmplification(amplification);
	B2.setNoiseAmplitude(noiseAmplitude);
	B2.setSamplingRate(samplesPerSymbol);
	B2.setDelay(delay);
	B2.setPosReferenceValue(0);
	B2.setNegReferenceValue(0);

	BitErrorRate B3{ vector<Signal*> { &S2, &S0 }, vector<Signal*> { &S2 } };
	B3.setConfidence(confidence);
	B3.setMidReportSize(midReportSize);

	Sink B4{ vector<Signal*> { &S2 }, vector<Signal*> {} };
	B4.setNumberOfSamples(numberOfBitsReceived*samplesPerSymbol);
	B4.setDisplayNumberOfSamples(true);

	// #####################################################################################################
	// ########################### System Declaration and Inicialization ###################################
	// #####################################################################################################

	System MainSystem{ vector<Block*> { &B1, &B2, &B3, &B4 } };

	// #####################################################################################################
	// #################################### System Run #####################################################
	// #####################################################################################################
	
	MainSystem.run();

	return 0;

}