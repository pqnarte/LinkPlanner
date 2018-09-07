# include "netxpto_20180118.h"

# include "binary_source_20180118.h"
# include "m_qam_mapper_20180118.h"
# include "discrete_to_continuous_time_20180118.h"
# include "pulse_shaper_20180111.h"
# include "local_oscillator_20180130.h"
# include "iq_modulator_20180130.h"
# include "photodiode_old_20180118.h"
# include "ideal_amplifier_20180118.h"
# include "sampler_20171119.h"
# include "optical_hybrid_20180118.h"
# include "adc_20180423.h"
# include "resample_20180423.h"
# include "quantizer_20180423.h"
# include "cpe_20180423.h"
#include "dsp_20180423.h"
# include "real_to_complex_20180221.h"
# include "sink.h"
# include <limits>

int main(){

	// #####################################################################################################
	// ################################### System Input Parameters #########################################
	// #####################################################################################################
	double inf = std::numeric_limits<double>::infinity();
	BinarySourceMode sourceMode{ PseudoRandom };
	int patternLength{ 5 };
	string bitStream{ "0" };
	double bitPeriod{ 1.0 / 2.5e9 };
	vector<t_iqValues> iqAmplitudes{ { { 1,1 },{ -1,1 },{ -1,-1 },{ 1,-1 } } };
	int numberOfBits{ 1000 };
	int numberOfSamplesPerSymbol{ 16 };
	double rollOffFactor{ 0.3 };
	int impulseResponseTimeLength{ 16 };
	double samplingPeriod{ 2*bitPeriod/numberOfSamplesPerSymbol};
	double wavelength = 1.55e-6;
	
	double localOscillatorPower1 = 1;
	double localOscillatorPower2 = 1;
	double localOscillatorPhase = 0;
	double responsivity = 1;
	double idealAmpGain = 0.26; //0.26, 10
	double qtMaxValue = 2.0;
	double qtMinValue = -2.0;
	double adcNbits = 64;
	double rFactor{ 1.0 };
	int nTapsCPE{ 1 };
	string methodType = "BPS"; // VV or BPS
	string BPStype = "A"; // A or B
	int NTestPhase = 32;
	int M = 4;

	// #####################################################################################################
	// ########################### Signals Declaration and Inicialization ##################################
	// #####################################################################################################
	
	Binary S1{ "S1.sgn" };

	TimeDiscreteAmplitudeDiscreteReal S2{ "S2.sgn" };
	TimeDiscreteAmplitudeDiscreteReal S3{ "S3.sgn" };
	TimeContinuousAmplitudeDiscreteReal S4{ "S4.sgn" };
	TimeContinuousAmplitudeDiscreteReal S5{ "S5.sgn" };	
	TimeContinuousAmplitudeContinuousReal S6{ "S6.sgn" };
	TimeContinuousAmplitudeContinuousReal S7{ "S7.sgn" };	
	BandpassSignal S8{ "S8.sgn" };
	BandpassSignal S9{ "S9.sgn" };
	OpticalSignal S10{ "S10.sgn" };
	OpticalSignal S11("S11.sgn");
	OpticalSignal S12("S12.sgn");
	OpticalSignal S13("S13.sgn");
	OpticalSignal S14("S14.sgn");
	TimeContinuousAmplitudeDiscreteReal S15("S15.sgn");
	TimeContinuousAmplitudeDiscreteReal S16{ "S16.sgn" };
	TimeContinuousAmplitudeDiscreteReal S17{ "S17.sgn" };
	TimeContinuousAmplitudeDiscreteReal S18{ "S18.sgn" };
	TimeContinuousAmplitudeDiscreteReal S19{ "S19.sgn" };
	TimeContinuousAmplitudeDiscreteReal S20{ "S20.sgn" };
	//TimeContinuousAmplitudeDiscreteReal S21{ "S21.sgn" };
	//TimeContinuousAmplitudeDiscreteReal S22{ "S22.sgn" };
	//BandpassSignal S23{ "S23.sgn" };

	//BandpassSignal S21{ "S21.sgn" };
	//S21.setFirstValueToBeSaved(320);

	TimeContinuousAmplitudeDiscreteReal S21{ "S21.sgn" };
	TimeContinuousAmplitudeDiscreteReal S22{ "S22.sgn" };

	Binary S23{ "S23.sgn" };

	// #####################################################################################################
	// ########################### Blocks Declaration and Inicialization ###################################
	// #####################################################################################################

	BinarySource B1{ vector<Signal*> {}, vector<Signal*> { &S1, &S23 } };
	B1.setMode(sourceMode);
	B1.setPatternLength(patternLength);
	B1.setBitStream(bitStream);
	B1.setBitPeriod(bitPeriod);
	B1.setNumberOfBits(numberOfBits);
	
	MQamMapper B2{ vector<Signal*> { &S1 }, vector<Signal*> { &S2, &S3 } };
	B2.setIqAmplitudes(iqAmplitudes);
	//B2.setM(M);

	DiscreteToContinuousTime B3{ vector<Signal*> { &S2 }, vector<Signal*> { &S4 } };
	B3.setNumberOfSamplesPerSymbol(numberOfSamplesPerSymbol);
	
	DiscreteToContinuousTime B4{ vector<Signal*> { &S3 }, vector<Signal*> { &S5 } };
	B4.setNumberOfSamplesPerSymbol(numberOfSamplesPerSymbol);

	PulseShaper B5{ vector<Signal*> { &S4 }, vector<Signal*> { &S6 } };
	B5.setRollOffFactor(rollOffFactor);
	B5.setImpulseResponseTimeLength(impulseResponseTimeLength);
	B5.setSeeBeginningOfImpulseResponse(false);

	PulseShaper B6{ vector<Signal*> { &S5 }, vector<Signal*> { &S7 } };
	B6.setRollOffFactor(rollOffFactor);
	B6.setImpulseResponseTimeLength(impulseResponseTimeLength);
	B6.setSeeBeginningOfImpulseResponse(false);

	LocalOscillator B7{ vector<Signal*> {}, vector<Signal*> { &S8 } };
	B7.setLaserLinewidth(5e5);
	B7.setLaserRIN(0.0);
	B7.setSamplingPeriod(samplingPeriod);
	B7.setSymbolPeriod(2*bitPeriod);

	IqModulator B8{ vector<Signal*> {&S6, &S7, &S8 }, vector<Signal*> { &S9 } };

	// QAM Receiver side//
	LocalOscillator B9{ vector<Signal*> {}, vector<Signal*> {&S10} };
	B9.setLaserLinewidth(0e5);
	B9.setLaserRIN(0.0);
	B9.setSamplingPeriod(samplingPeriod);
	B9.setSymbolPeriod(2 * bitPeriod);

	OpticalHybrid B10{ vector<Signal*> {&S10, &S9}, vector<Signal*> {&S11, &S12, &S13, &S14} };

	Photodiode B11{ vector<Signal*> { &S11, &S12 }, vector<Signal*> {&S15} };
	B11.setResponsivity(responsivity);

	Photodiode B12{ vector<Signal*> { &S13, &S14 }, vector<Signal*> {&S16} };
	B12.setResponsivity(responsivity);

	IdealAmplifier B13{ vector<Signal*> { &S15 }, vector<Signal*> {&S17} };
	B13.setGain(idealAmpGain);

	IdealAmplifier B14{ vector<Signal*> { &S16 }, vector<Signal*> {&S18} };
	B14.setGain(idealAmpGain);

	/*Resample B15{ vector<Signal*> { &S17 }, vector<Signal*> {&S19} };
	B15.setOutRateFactor(rFactor);

	Resample B16{ vector<Signal*> { &S18 }, vector<Signal*> {&S20} };
	B16.setOutRateFactor(rFactor);

	Quantizer B17{ vector<Signal*> { &S19 }, vector<Signal*> { &S21 } };
	B17.setResolution(adcNbits);
	B17.setMaxValue(qtMaxValue);
	B17.setMinValue(qtMinValue);
	B17.setSamplingPeriod(samplingPeriod);
	

	Quantizer B18{ vector<Signal*> { &S20 }, vector<Signal*> { &S22 } };
	B18.setResolution(adcNbits);
	B18.setMaxValue(qtMaxValue);
	B18.setMinValue(qtMinValue);
	B18.setSamplingPeriod(samplingPeriod);

	Real2Complex B19{ vector<Signal*> { &S21, &S22 }, vector<Signal*> { &S23 } };

	CPE B20{ vector<Signal*> { &S23 }, vector<Signal*> { &S24 } };
	B20.setnTaps(nTapsCPE);
	B20.setmethodType(methodType);*/

	ADC B15{ vector<Signal*> {&S17}, vector<Signal*> {&S19} };
	B15.setQuantizerSamplingPeriod(samplingPeriod);
	B15.setResampleOutRateFactor(rFactor);
	B15.setQuantizerResolution(adcNbits);
	B15.setQuantizerMaxValue(qtMaxValue);
	B15.setQuantizerMinValue(qtMinValue);
	B15.setSamplingPeriod(samplingPeriod);
	//B15.setSaveInternalSignals(true);

	ADC B16{ vector<Signal*> {&S18}, vector<Signal*> {&S20} };
	B16.setQuantizerSamplingPeriod(samplingPeriod);
	B16.setResampleOutRateFactor(rFactor);
	B16.setQuantizerResolution(adcNbits);
	B16.setQuantizerMaxValue(qtMaxValue);
	B16.setQuantizerMinValue(qtMinValue);
	B16.setSamplingPeriod(samplingPeriod);
	//B16.setSaveInternalSignals(true);

	DSP B17{ vector<Signal*> { &S19, &S20 }, vector<Signal*> {&S21, &S22} };
	B17.setCPESamplingPeriod(samplingPeriod);
	B17.setCPEnTaps(nTapsCPE);
	B17.setCPEmethodType(methodType);
	B17.setCPEBPStype(BPStype);
	B17.setSamplingPeriod(samplingPeriod);
	B17.setCPETestPhase(NTestPhase);
	B17.setCPEmQAM(M);

	Sink B21{ vector<Signal*> { &S21, &S22 }, vector<Signal*> {} };
	//B9.setNumberOfSamples(5000);
	//B9.setDisplayNumberOfSamples(true);

	Sink B22{ vector<Signal*> { &S23 }, vector<Signal*> {} };

	// #####################################################################################################
	// ########################### System Declaration and Inicialization ###################################
	// #####################################################################################################


	System MainSystem{ vector<Block*> { &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8, &B9, &B10, &B11, &B12, &B13, &B14, &B15, &B16, &B17, &B21, &B22} };

	//System MainSystem{ vector<Block*> { &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8, &B9, &B10, &B11, &B12, &B13, &B14, &B15, &B16, &B17, &B18, &B19, &B20, &B21, &B22} };

	// #####################################################################################################
	// #################################### System Run #####################################################
	// #####################################################################################################
	
	MainSystem.run();

	return 0;

}