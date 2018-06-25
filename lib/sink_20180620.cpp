# include "sink_20180620.h"



using namespace std;

Sink::Sink(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) {

  numberOfInputSignals = (int) InputSig.size();
  numberOfOutputSignals = (int) OutputSig.size();

  inputSignals = InputSig;
  output_file.open(asciiFilePath,ios::binary);

  if (!output_file.is_open()) { cerr << "ERROR: Could not open file " << this->asciiFilePath << endl; exit(1); }
}

bool Sink::runBlock(void)
{

	int ready = inputSignals[0]->ready();

	int process;
	if (numberOfSamples >= 0) {
		process = std::min((long int)ready, numberOfSamples);
	}
	else {
		process = ready;
	}
	 
	if ((process == 0) || (numberOfSamples == 0) || (numberOfBytesToSaveInFile == 0)) {
		output_file.close();
		return false;
	}
	if (numberOfBitsToSkipBeforeSave < 0) { cerr << "ERROR: Variable 'numberOfBitsToSkipBeforeSave' cannot have a negative value." << endl; exit(1); }
	if (numberOfBytesToSaveInFile < 0) { cerr << "ERROR: Variable 'numberOfBytesToSaveInFile' cannot have a negative value." << endl; exit(1); }

	//Sink signal to file
	if (numberOfBitsToSkipBeforeSave > 0) {//Sinks skip bits
		int min = std::min((long int)process,numberOfBitsToSkipBeforeSave);
		for (int i = 0; i < min; i++) {
			inputSignals[0]->bufferGet();
			numberOfBitsToSkipBeforeSave--;
			numberOfSamples--;
		}
		return true;
	}
	//Calculates the number of full bytes that are still available in the buffer
	int numBytesToSave = std::min((long int)(process / 8), numberOfBytesToSaveInFile);
	//From this point forward we have the guarantee that we have at least 'numBytesToSave' bytes remaining in the buffer
	for (int numBytes = 0; numBytes < numBytesToSave; numBytes++) {
		char charToWrite = 0; //0000 0000
		for (int i = 7; i >= 0; i--) {
			t_binary tmp1;
			t_binary* tmp = &tmp1;
			inputSignals[0]->bufferGet(tmp);
			char c = (char)(*tmp);
			c = c << i;
			charToWrite = charToWrite | c;
		}
		output_file.put(charToWrite);
		numberOfBytesToSaveInFile--;
	}
	//for (int i = 0; i < process; i++) inputSignals[0]->bufferGet(); //Sinks the remaining bits
	int numSavedBits = numBytesToSave * 8;
	numberOfSamples = numberOfSamples - numSavedBits;
	if (numSavedBits == 0) { //Remaining bits. Means that process < 8
		//We are going to append zeros until 8 bits are available and write the char to the file
		char charToWrite = 0;
		for (int i = 7; i >= 8-process; i--) {
			t_binary tmp1;
			t_binary* tmp = &tmp1;
			inputSignals[0]->bufferGet(tmp);
			char c = (char)(*tmp);
			c = c << i;
			charToWrite = charToWrite | c;
		}
		output_file.put(charToWrite);
	}
	if (displayNumberOfSamples) cout << numberOfSamples << "\n";

	return true;
}
