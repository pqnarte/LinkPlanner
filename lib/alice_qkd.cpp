#include "netxpto.h"
#include "alice_qkd.h"

AliceQKD::AliceQKD(vector <Signal*> &inputSignal, vector<Signal *> &outputSignal) :SuperBlock(inputSignal, outputSignal) {
	numberOfInputSignals = inputSignal.size();
	numberOfOutputSignals = outputSignal.size();

	signal_value_type sType = outputSignals[0]->getValueType();

	switch (numberOfOutputSignals) {
	case 1:
		B1.initializeBlock(vector<Signal*> {}, vector<Signal*> { &S1});
		B2.initializeBlock(vector<Signal*> { &S1 }, vector<Signal*> { &S2, &S3 });
		B3.initializeBlock(vector<Signal*> { &S2 }, vector<Signal*> { &S4 });
		B4.initializeBlock(vector<Signal*> { &S4 }, vector<Signal*> { &S5 });
		B5.initializeBlock(vector<Signal*> { &S4 }, vector<Signal*> {});
		
		setModuleBlocks({ &B1, &B2, &B3, &B4, &B5 });
		break;
	default:
		cout << "ERRO: alice_qkd.cpp" << "\n";
	}
}

void AliceQKD::set(int opt) {

	// Basic Configuration

	if (opt == 0) {
		setMode(DeterministicAppendZeros);
		setBitPeriod(1.0 / 50e9);
		setPatternLength(5);
		setNumberOfBits(10000);
		setNumberOfSamplesPerSymbol(16); //antes 32
		setRollOffFactor(0.3);
		setIqAmplitudes({ { -45, 0 },{ 0, 0 },{ 45, -0 },{ 90, 0 } });
		setOutputOpticalPower_dBm(0); //antes 0
		setSaveInternalSignals(true);
	}

	return;
}