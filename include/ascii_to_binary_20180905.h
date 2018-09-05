# include "netxpto_20180418.h"
# include <bitset>

using namespace std;

class AsciiToBinary : public Block {

public:
	AsciiToBinary() {};
	AsciiToBinary(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) : Block(InputSig, OutputSig) { };

	void initialize(void);

	bool runBlock(void);

};