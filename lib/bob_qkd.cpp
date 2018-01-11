#include "netxpto.h"
#include "bob_qkd.h"

BobQKD::BobQKD(vector<Signal*> &inputSignal, vector <Signal*> &outputSignal) : SuperBlock(inputSignal, outputSignal) {


	numberOfInputSignals = (int)inputSignal.size();
	numberOfOutputSignals = (int)outputSignal.size();

	BB0.initializeBlock(vector<Signal*>{inputSignals[0]}, vector<Signal*>{&S1});
	BB1.initializeBlock(vector<Signal*>{&S1}, vector<Signal*>{&S2});
	BB1.setNumberOfSamplesPerSymbol( 16 );
	BB2.initializeBlock(vector<Signal*>{&S2}, vector<Signal*>{&S3});
	BB9.initializeBlock(vector<Signal*>{&S3}, vector<Signal*>{&S4});
	

	setModuleBlocks({ &BB0, &BB1, &BB2 , &BB9});
	
}