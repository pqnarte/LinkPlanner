#include "alice_qkd.h"

AliceQKD::AliceQKD(vector<Signal*> &inputSignal, vector <Signal*> &outputSignal) : SuperBlock(inputSignal, outputSignal) {

	
	numberOfInputSignals = (int) inputSignal.size();
	numberOfOutputSignals = (int) outputSignal.size();


	BA1.initializeBlock(vector<Signal*>{inputSignals[1]}, vector<Signal*>{&alice_1, &alice_2});
	BA2.initializeBlock(vector<Signal*>{&alice_1}, vector<Signal*>{&alice_3});
	BA4.initializeBlock(vector<Signal*>{&alice_2}, vector<Signal*>{});
	BA3.initializeBlock(vector<Signal*>{&alice_3}, vector<Signal*>{&S4});
	BA11.initializeBlock(vector<Signal*>{}, vector<Signal*>{&alice_8});
	BA11.setMode(DeterministicCyclic);
	BA11.setBitStream("01");
	BA6.initializeBlock(vector<Signal*>{inputSignals[2], &alice_8}, vector<Signal*>{&S5, &alice_7});
	BA12.initializeBlock(vector<Signal*>{&alice_7}, vector<Signal*>{});
	BA13.initializeBlock(vector<Signal*>{}, vector<Signal*>{&alice_11});
	BA13.setMode(DeterministicCyclic);
	BA13.setBitStream("10");
	BA8.initializeBlock(vector<Signal*>{inputSignals[3],&alice_11}, vector<Signal*>{&S8,&alice_10});
	BA14.initializeBlock(vector<Signal*>{&alice_10}, vector<Signal*>{});
	BA5.initializeBlock(vector<Signal*>{inputSignals[0], &S4, &S5, &S8}, vector<Signal*>{outputSignals[0], outputSignals[1], outputSignals[2], outputSignals[3]});

	setModuleBlocks({ &BA1 , &BA2, &BA4, &BA3 , &BA11, &BA6, &BA12, &BA13, &BA8, &BA14, &BA5});

}

//Basic configuration
void AliceQKD::set(int opt) {

	if (opt == 0) {
		setNumberOfSamplesPerSymbol(16);
		setIqAmplitudes({ { -45.0,0.0 },{ 0.0,0.0 },{ 45.0,0.0 },{ 90.0,0.0 } });
		setNumberOfSamples(1000);
	}

	return;
}
