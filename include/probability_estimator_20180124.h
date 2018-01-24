#ifndef  PROBABILITY_ESTIMATOR_H
#define PROBABILITY_ESTIMATOR_H

#include "netxpto.h"

class ProbabilityEstimator : public Block {

	/*Input Parameters*/


	/*State variables*/	

public:

	 double NumberOf1 = 0;
	 double NumberOf0 = 0;
	 double receivedData = 0;

	ProbabilityEstimator() { };
	ProbabilityEstimator(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

	void initialize(void);

	bool runBlock(void);

private:
	int firstTime = 1;


};

#endif // ! PROBABILITY_ESTIMATOR_H

