#include "netxpto.h"
#include "alice_qkd.h"

AliceQKD::AliceQKD(vector<Signal*> &inputSignal, vector <Signal*> &outputSignal) : SuperBlock(inputSignal, outputSignal) {

	
	numberOfInputSignals = (int) inputSignal.size();
	numberOfOutputSignals = (int) outputSignal.size();


	BA1.initializeBlock(vector<Signal*>{inputSignals[1]}, vector<Signal*>{&S1, &S2});
	BA2.initializeBlock(vector<Signal*>{&S1}, vector<Signal*>{&S3});
	BA4.initializeBlock(vector<Signal*>{&S2}, vector<Signal*>{});
	BA3.initializeBlock(vector<Signal*>{&S3}, vector<Signal*>{&S4});
	BA11.initializeBlock(vector<Signal*>{}, vector<Signal*>{&S7});
	BA11.setMode(DeterministicCyclic);
	BA11.setBitStream("01");
	BA6.initializeBlock(vector<Signal*>{inputSignals[2], &S7}, vector<Signal*>{&S5, &S6});
	BA12.initializeBlock(vector<Signal*>{&S6}, vector<Signal*>{});
	BA5.initializeBlock(vector<Signal*>{inputSignals[0], &S4, &S5}, vector<Signal*>{outputSignals[0], outputSignals[1], outputSignals[2]});

	setModuleBlocks({ &BA1 , &BA2, &BA4, &BA3 , & BA11, &BA6, &BA12,&BA5});

}

//Basic configuration
void AliceQKD::set(int opt) {

	if (opt == 0) {
		setNumberOfSamplesPerSymbol(16);
		setIqAmplitudes({ { -45.0,0.0 },{ 0.0,0.0 },{ 45.0,0.0 },{ 90.0,0.0 } });
		setSaveInternalSignals(true);
		setNumberOfSamples(1000);
	}

	return;
}