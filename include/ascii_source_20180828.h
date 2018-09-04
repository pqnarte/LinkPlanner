# ifndef ASCII_SOURCE_H_
# define ASCII_SOURCE_H_

# include "netxpto_20180418.h"

# include <algorithm> 
# include <iostream>
# include <fstream>
# include <string>

/*
	Terminate - Creates a signal with asciiString as sequence
	AppendZeros - Creates a signal with asciiString as the starting sequence and appends zeros
	Cyclic - Creates a signal with asciiString as the starting sequence and repeats it
*/
enum AsciiSourceMode { Terminate, AppendZeros, Cyclic };

using namespace std;

class AsciiSource : public Block {

private:
	//Input Parameters
	AsciiSourceMode mode{ Terminate };
	string asciiString{ "" }; //The sequence that will be written to the signal.
	string asciiFilePath{ "text_file.txt" }; //The file from where the block will read the asciiString pattern
	//Auxiliary variables
	long charIndex{ -1 };
	ifstream input_file;

public:
	AsciiSource() {};
	AsciiSource(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) : Block(InputSig, OutputSig) { };

	void initializeBlock(vector<Signal *> &InputSig, vector<Signal *> &OutputSig);
	void initialize(void);

	bool runBlock(void);

	void setMode(AsciiSourceMode m) { mode = m; }
	AsciiSourceMode getMode() { return mode; }

	void setasciiString(string s) { asciiString = s; }
	string getasciiString() { return asciiString; }

	void setAsciiFilePath(string p) { asciiFilePath = p; }
	string getAsciiFilePath() { return asciiFilePath; }

};

# endif