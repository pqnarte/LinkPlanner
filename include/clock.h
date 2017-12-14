# ifndef CLOCK_H_
# define CLOCK_H_

# include "netxpto.h"

class Clock : public Block {


	/* input parameters */
	double period{ 0.0 };
	double phase{ 0.0 };

	double samplingPeriod{ 0.0 };

	/* state variables */
	int index{ 0 };
	double first{ true };
	int delay{ 0 };

	
public:

	Clock() {};
	Clock(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

	void initialize(void);
	bool runBlock(void);

	void setClockPeriod(double per) { period = per; }
	void setClockPhase(double pha) { phase = pha; }
	void setSamplingPeriod(double sPeriod) { samplingPeriod = sPeriod; }

};

# endif
