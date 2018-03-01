// Currently mostly copied from BER
# ifndef PROGRAM_INCLUDE_SRN_ESTIMATOR_
# define PROGRAM_INCLUDE_SRN_ESTIMATOR_

# include "netxpto_20180118.h"
# include <vector>

// Calculates the BER between two binary signals
class SNREstimator : public Block {

	bool firstTime{ true };

public:

	SNREstimator(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

	void initialize(void);
	bool runBlock(void);

	void setPeakThreshold(t_real setPeak) { peakThreshold = setPeak; };
	t_real getPeakThreshold() { return peakThreshold; };

private:

	t_real peakThreshold;

};


#endif // !PROGRAM_INCLUDE_SRN_ESTIMATOR_