#include "bob_qkd.h"

BobQKD::BobQKD(vector<Signal*> &inputSignal, vector <Signal*> &outputSignal) : SuperBlock(inputSignal, outputSignal) {


	numberOfInputSignals = (int)inputSignal.size();
	numberOfOutputSignals = (int)outputSignal.size();

	BB0.initializeBlock(vector<Signal*>{inputSignals[0]}, vector<Signal*>{&Bob_1});
	BB1.initializeBlock(vector<Signal*>{&Bob_1}, vector<Signal*>{&Bob_2});
	BB1.setNumberOfSamplesPerSymbol(16);
	BB2.initializeBlock(vector<Signal*>{&Bob_2}, vector<Signal*>{&Bob_8});
	BB3.initializeBlock(vector<Signal*>{inputSignals[1]}, vector<Signal*>{&Bob_3});
	BB4.initializeBlock(vector<Signal*>{&Bob_3}, vector<Signal*>{&CLKB_1, &CLKB_2});
	BBteste.initializeBlock(vector<Signal*>{inputSignals[2], inputSignals[3]}, vector<Signal*>{&Bob_9, &Bob_10});
	BB10.initializeBlock(vector<Signal*>{&Bob_9, &Bob_10}, vector<Signal*>{&Bob_7});
	BBSink.initializeBlock(vector<Signal*>{&Bob_7}, vector<Signal*>{});
	BBSink.setNumberOfSamples(1000);
	BB9.initializeBlock(vector<Signal*>{&Bob_8, &CLKB_1, &CLKB_2}, vector<Signal*>{&S4, &CLKB_out1, &CLKB_out2});


	setModuleBlocks({ &BB0, &BB1, &BB2 ,&BB3, &BB4, &BBteste, &BB10, &BBSink, &BB9 });

}