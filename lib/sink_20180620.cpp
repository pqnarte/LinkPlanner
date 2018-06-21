# include "sink_20180620.h"



using namespace std;

Sink::Sink(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) {

  numberOfInputSignals = (int) InputSig.size();
  numberOfOutputSignals = (int) OutputSig.size();

  inputSignals = InputSig;
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
	 
	if ((process == 0) || (numberOfSamples==0)) return false;

/*	if ((inputSignals[0])->getType().compare("TimeDiscreteAmplitudeDiscreteReal"))
		for (int i = 0; i<process; i++) static_cast<TimeDiscreteAmplitudeDiscreteReal *>(inputSignals[0])->bufferGet();

	if ((inputSignals[0])->getType().compare("Binary"))
		for (int i = 0; i<process; i++) static_cast<Binary *>(inputSignals[0])->bufferGet();

	if ((inputSignals[0])->getType().compare("TimeDiscreteAmplitudeContinuousReal"))
		for (int i = 0; i<process; i++) static_cast<TimeDiscreteAmplitudeContinuousReal *>(inputSignals[0])->bufferGet();

	if ((inputSignals[0])->getType().compare("TimeDiscreteAmplitudeContinuousComplex"))
	for (int i = 0; i<process; i++) static_cast<TimeDiscreteAmplitudeContinuousComplex *>(inputSignals[0])->bufferGet();

	if ((inputSignals[0])->getType().compare("TimeContinuousAmplitudeDiscreteReal"))
		for (int i = 0; i<process; i++) static_cast<TimeContinuousAmplitudeDiscreteReal *>(inputSignals[0])->bufferGet();

	if ((inputSignals[0])->getType().compare("TimeContinuousAmplitudeContinuousComplex"))
		for (int i = 0; i<process; i++) static_cast<TimeContinuousAmplitudeContinuousComplex *>(inputSignals[0])->bufferGet();*/

	//Sink signal to file
	ofstream output_file(asciiFilePath,ios::app);
	if (output_file.is_open()) {
		for (int i = 1; i <= numberOfBitsToSkipBeforeSave; i++) { inputSignals[0]->bufferGet(); } //Sinks skip bits
		//Calculates the number of full bytes that are still available in the buffer
		int numBytesToSave = std::min((process - numberOfBitsToSkipBeforeSave) / 8, numberOfBytesToSaveInFile);
		//From this point forward we have the guarantee that we have at least 'numBytesToSave' bytes remaining in the buffer
		for (int numBytes = 0; numBytes < numBytesToSave; numBytes++) {
			char charToWrite = 0; //0000 0000
			for (int i = 7; i >= 0; i--) {
				t_binary tmp1 = 0;
				t_binary* tmp = &tmp1;
				inputSignals[0]->bufferGet(tmp);
				char c = (char)(*tmp);
				c = c << i;
				charToWrite = charToWrite | c;
			}
			output_file.put(charToWrite);
		}
		output_file.close();
	}else {
		cerr << "ERROR: Could not open file " << this->asciiFilePath << endl;
		exit(1);
	}
	while (!inputSignals[0]->getBufferEmpty()) { inputSignals[0]->bufferGet(); } //Sinks the remaining bits
	//for (int i = 0; i<process; i++) (inputSignals[0])->bufferGet();

	numberOfSamples = numberOfSamples - process;
	if (displayNumberOfSamples) cout << numberOfSamples << "\n";

	return true;
}
