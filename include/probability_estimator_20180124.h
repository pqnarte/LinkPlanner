#ifndef  PROBABILITY_ESTIMATOR_H
#define PROBABILITY_ESTIMATOR_H

#include "netxpto.h"

class ProbabilityEstimator : public Block {

	/*Input Parameters*/
	double probabilityX{ 0.0 };
	double probabilityY{ 0.0 };
	double zscore{ 2.576 }; // For a 99% Confidence Interval

	/*State variables*/	

public:

	 double NumberOf1 = 0;
	 double NumberOf0 = 0;
	 double receivedData = 0;

	ProbabilityEstimator() { };
	ProbabilityEstimator(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

	void initialize(void);

	bool runBlock(void);

	void setProbabilityExpectedX(double probx) { probabilityX = probx; };
	double getProbabilityExpectedX() { return probabilityX; };

	void setProbabilityExpectedY(double proby) { probabilityY = proby; };
	double getProbabilityExpectedY() { return probabilityY; };

	void setZScore(double z) { zscore = z; };
	double getZScore() { return zscore; };



};

#endif // ! PROBABILITY_ESTIMATOR_H

