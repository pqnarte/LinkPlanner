# ifndef PROGRAM_INCLUDE_HAMMING_CODER_H_
# define PROGRAM_INCLUDE_HAMMING_CODER_H_

# include "netxpto_20180418.h"
# include <vector>

// Takes a sampling of the input electrical signal
class HammingCoder : public Block {

public:
	void initialize(void);
	bool runBlock(void);

	void setParityBits(int s_n);
	int getParityBits();

	HammingCoder() {};
	HammingCoder(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

private:
	int parityBits = 3;		/* Default: Hamming Code (7, 4) */

	int k_array[7] = { 1, 4, 11, 26, 57, 120, 247 };
	int n_array[7] = { 3, 7, 15, 31, 63, 127, 255 };
	vector<vector<int>> G;

	void setGMatrix(int s_n);
};

#endif // !PROGRAM_INCLUDE_HAMMING_CODER_H_
