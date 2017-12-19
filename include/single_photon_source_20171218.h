# ifndef SINGLE_PHOTON_SOURCE_H_
# define SINGLE_PHOTON_SOURCE_H_


class SinglePhotonSource : public Block {

	

public:
	/* input parameters */

	/*	Methods	*/

	SinglePhotonSource(vector<Signal *> &inputSignals, vector<Signal *> &outputSignals) : Block(inputSignals, outputSignals){};

	void initialize(void);

	bool runBlock(void);

};

#endif