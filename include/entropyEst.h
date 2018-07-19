#pragma once
# include <algorithm>   // std::min
# include <string>		// compare

# include "netxpto_20180118.h"

class entropyEst : public Block {


public:
	
	long int numberOfSamples{ -1 };
	int w;

	//Methods
	entropyEst(){};
	entropyEst(vector<Signal *> &InputSig, int window);

	bool runBlock(void);


};

