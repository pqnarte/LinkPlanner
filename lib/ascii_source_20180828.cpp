#include "ascii_source_20180828.h"

void AsciiSource::initializeBlock(vector<Signal*>& InputSig, vector<Signal*>& OutputSig)
{
	Block::initializeBlock(InputSig,OutputSig);
	input_file.open(asciiFilePath, ios::binary);
	if (input_file)
		asciistring = std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
	else
		throw exception("Could not open file!");
}

void AsciiSource::initialize(void)
{
	numberOfOutputSignals = (int)outputSignals.size();

	for (auto i = 0; i < numberOfOutputSignals; ++i) {
		outputSignals[i]->setSamplingPeriod(outputSignals[i]->getSymbolPeriod());
		outputSignals[i]->setSamplesPerSymbol(1.0);
		outputSignals[i]->setFirstValueToBeSaved(1);
	}
}

bool AsciiSource::runBlock(void)
{

	long int space = outputSignals[0]->space();
	for (auto k = 1; k < numberOfOutputSignals; k++) {
		long int aux = outputSignals[k]->space();
		space = std::min(space, aux);
	}
	long int process;
	process = space;
	if (process <= 0) return false;

	for (int i = 0; i < process; i++) {
		charIndex += 1;
		if (charIndex == asciistring.length()) {
			if (mode == Terminate) return false;
			else if (mode == AppendZeros) {
				for (int j = 0; j < numberOfOutputSignals; j++) {
					outputSignals[j]->bufferPut('\0'); //Appends the null character until the buffer is filled
				}
				charIndex -= 1;
				continue;
			}
			charIndex = charIndex % asciistring.length();
		}
		for (int k = 0; k < numberOfOutputSignals; k++) {
			char aux = asciistring[charIndex];
			outputSignals[k]->bufferPut(aux);
		}
	}

	return true;
}
