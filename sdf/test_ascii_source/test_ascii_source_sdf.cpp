# include "netxpto_20180418.h"
# include "ascii_source_20180828.h"
# include "sink_20180118.h"
# include "ascii_to_binary_20180905.h"

int main()
{
	//Signals
	Ascii S1{ "S1.sgn", 8 };

	Binary S2{ "S2.sgn" , 8 };

	//Blocks
	AsciiSource B1{ vector<Signal*>{},vector<Signal*>{&S1} };
	B1.setAsciiFilePath("test.txt");
	B1.setMode(Terminate);

	AsciiToBinary B2{ vector<Signal*>{&S1} , vector<Signal*>{&S2} };

	Sink B3{ vector<Signal*>{&S2} , vector<Signal*>{} };
	B3.setDisplayNumberOfSamples(true);

	System Main{ vector<Block*>{&B1, &B2, &B3} };
	Main.run();

	return 0;
}
