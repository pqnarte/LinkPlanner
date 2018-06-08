# ifndef PROGRAM_INCLUDE_SAMPLER_H_
# define PROGRAM_INCLUDE_SAMPLER_H_

# include "netxpto_20180118.h"
# include <vector>

class HammingCoder : public Block {

	/* Inputa Parameters */
	int n{ 7 };
	int k{4};

	/* State Variables */
	// G
	// d
	// c

public:

	void initialize(void);
	bool runBlock(void);

	void setN(int s_n) { n = s_n; };
	int getN() { return n; };
	
	HammingCoder() {};
	HammingCoder(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

};


#endif // !PROGRAM_INCLUDE_SAMPLER_H_
