#include "netxpto.h"
#include "alice_qkd.h"

AliceQKD::AliceQKD (vector<Signal*> &inputSignal, vector <Signal*> &outputSignal): SuperBlock(inputSignal, outputSignal){

	numberOfInputSignals = inputSignal.size();
	numberOfOutputSignals = outputSignal.size();

	signal_value_type sType = outputSignals[0]->getValueType();

	B1.initializeBlock(vector<Signal*>{}, vector <Signal*> {&S1});
	B2.initializeBlock(vector<Signal*>{&S1}, vector<Signal*>{&S2, &S3});
	B3.initializeBlock(vector<Signal*>{&S2}, vector<Signal*>{&S4});
	B4.initializeBlock(vector<Signal*>{&S4}, vector<Signal*>{&S5});
	B6.initializeBlock(vector <Signal*>{}, vector <Signal*>{&CLK_A});

	B5.setNumberOfSamples(1000);

	setModuleBlocks({ &B1,&B2 });

}

//Basic configuration
void AliceQKD::set(int opt) {

	if (opt == 0) {
		setMode(DeterministicAppendZeros);
		setBitPeriod(1 / (2 * 1e3));
		setPatternLength(5);
		setNumberOfBits(100);
		setNumberOfSamplesPerSymbol(16);
		setIqAmplitudes({ { -45.0,0.0 },{ 0.0,0.0 },{ 45.0,0.0 },{ 90.0,0.0 } });
		setSaveInternalSignals(true);
	}

	return;
}