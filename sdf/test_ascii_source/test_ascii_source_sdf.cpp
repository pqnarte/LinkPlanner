# include "netxpto_20180418.h"
# include "ascii_source_20180828.h"
# include "sink_20180118.h"
# include "ascii_to_binary_20180905.h"
# include "binary_to_ascii_20180905.h"

int main()
{
	//Signals
	Ascii S1{ "S1.sgn", 8 };

	Binary S2{ "S2.sgn", 1 };

	Ascii S3{ "S3.sgn", 2 };

	//Blocks
	AsciiSource B1{ vector<Signal*>{},vector<Signal*>{&S1} };
	B1.setAsciiFilePath("test.txt"); //Loads the pattern from a file
	B1.setMode(Cyclic); //Possible values: Terminate, Cyclic, AppendZeros
	B1.setNumberOfCharacters(10); // Selects the number of characters to be generated

	AsciiToBinary B2{ vector<Signal*>{&S1} , vector<Signal*>{&S2} };
	
	BinaryToAscii B3{ vector<Signal*>{&S2} , vector<Signal*>{&S3} };

	Sink B4{ vector<Signal*>{&S3} , vector<Signal*>{} };
	B4.setDisplayNumberOfSamples(true);

	System Main{ vector<Block*>{&B1, &B2, &B3, &B4} };
	Main.run();

	return 0;
}
