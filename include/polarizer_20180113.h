#ifndef POLARIZE_H_
#define POLARIZER_H_

#include "netxpto_20180118.h"

enum functionalMode {Sender, Receiver};

class Polarizer : public Block{
	
	
public:
	// Input parameters
	functionalMode mode{ Sender };

	Polarizer (vector <Signal*> &inputSignals, vector <Signal*> &outputSignals) : Block(inputSignals, outputSignals) {};

	void initialize(void);

	bool runBlock(void);

	void setFunctionality(functionalMode s) { mode = s; };
	functionalMode const getFunctionMode(void) { return mode; };
	
};
#endif // !POLARIZE_H_

