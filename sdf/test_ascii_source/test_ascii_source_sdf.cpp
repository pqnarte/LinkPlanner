# include "..\..\include\netxpto_20180418.h"
# include "..\..\include\ascii_source_20180828.h"
# include "..\..\include\sink_20180118.h"

void main()
{

	Ascii S1{ "S1.sgn", 8 };

	AsciiSource B1{ vector<Signal*>{},vector<Signal*>{&S1} };
	B1.setAsciiFilePath("test.txt");
	B1.setMode(Terminate);


	Sink B2{ vector<Signal*>{&S1} , vector<Signal*>{} };
	B2.setDisplayNumberOfSamples(true);

	System Main{ vector<Block*>{&B1, &B2} };

	Main.run();

}
