#include "bob_qkd.h"

BobQKD::BobQKD(vector<Signal*> &inputSignal, vector <Signal*> &outputSignal) : SuperBlock(inputSignal, outputSignal) {
	BB0.initializeBlock(vector <Signal*> {inputSignals[0]}, vector<Signal*>{&Bob_1});

	BB1.initializeBlock(vector <Signal*> {&Bob_1}, vector<Signal*>{&Bob_2});

	BB2.initializeBlock(vector <Signal*> {&Bob_2}, vector<Signal*>{&Bob_8});

	BB3.initializeBlock(vector <Signal*> {inputSignals[1]}, vector<Signal*>{&Bob_3});
	BB4.initializeBlock(vector <Signal*> {&Bob_3}, vector<Signal*>{&CLKB_out1, &CLKB_out2});
	
	BB10.initializeBlock(vector <Signal*> {inputSignals[2], inputSignals[3]}, vector<Signal*>{&Bob_7, &Bob_11});

	BB5.initializeBlock(vector<Signal*>{&Bob_7, inputSignals[4] }, vector<Signal*>{&Bob_4, &Bob_10});

	BBSink1.initializeBlock(vector<Signal*>{&Bob_11}, vector<Signal*>{});
	BBSink1.setDisplayNumberOfSamples(true);

	BBSink.initializeBlock(vector<Signal*>{&Bob_4}, vector<Signal*>{});
	BBSink.setDisplayNumberOfSamples(true);

	BBSink0.initializeBlock(vector<Signal*>{&Bob_10}, vector<Signal*>{});
	BBSink0.setDisplayNumberOfSamples(true);


	BB9.initializeBlock(vector <Signal*> {&Bob_8, &CLKB_out1, &CLKB_out2}, vector<Signal*>{outputSignals[0], outputSignals[1], outputSignals[2]});

	setModuleBlocks({ &BB0, &BB1, &BB2, &BB3, &BB4, &BB10, &BB5, &BBSink1, &BBSink, &BBSink0, &BB9 });


}
