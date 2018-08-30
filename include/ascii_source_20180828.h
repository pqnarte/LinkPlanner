# ifndef ASCII_SOURCE_H_
# define ASCII_SOURCE_H_

# include "netxpto_20180418.h"

# include <algorithm> 
# include <iostream>
# include <fstream>
# include <string>

/*
	Terminate - Creates a signal with asciistring as sequence
	AppendZeros - Creates a signal with asciistring as the starting sequence and appends zeros
	Cyclic - Creates a signal with asciistring as the starting sequence and repeats it
*/
enum AsciiSourceMode { Terminate, AppendZeros, Cyclic };

using namespace std;

class AsciiSource : public Block {

private:
	//Input Parameters
	AsciiSourceMode mode{ Terminate };
	string asciistring{ "ABCabc" }; //The sequence that will be written to the signal.
	string asciiFilePath{ "text_file.txt" }; //The file from where the block will read the asciistring pattern
	//Auxiliary variables
	long charIndex{ -1 };
	ifstream input_file;

public:
	AsciiSource() {};
	AsciiSource(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) { initializeBlock(InputSig,OutputSig); };

	void initializeBlock(vector<Signal *> &InputSig, vector<Signal *> &OutputSig);
	void initialize(void);

	bool runBlock(void);

	void setMode(AsciiSourceMode m) { mode = m; }
	AsciiSourceMode getMode() { return mode; }

	void setAsciiString(string s) { asciistring = s; }
	string getAsciiString() { return asciistring; }

	void setAsciiFilePath(string p) { asciiFilePath = p; }
	string getAsciiFilePath() { return asciiFilePath; }

};

# endif