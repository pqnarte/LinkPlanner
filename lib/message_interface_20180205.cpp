
#include "message_interface_20180205.h"



void MessageProcessorAlice::initialize(void) {
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[1]->setSamplingPeriod(inputSignals[1]->getSamplingPeriod());
	outputSignals[1]->setSymbolPeriod(inputSignals[1]->getSymbolPeriod());
	outputSignals[1]->setSamplesPerSymbol(inputSignals[1]->getSamplesPerSymbol());
	outputSignals[1]->setFirstValueToBeSaved(inputSignals[1]->getFirstValueToBeSaved());
}

bool MessageProcessorAlice::runBlock(void) {

	/*Number of message ready to be read*/
	int readyIn = inputSignals[1]->ready();

	int spaceIn = spaceBufferIn();					//in units of bits
	spaceIn = (int) floor(spaceIn / messageDataLength);		//in units of messages

	int process = min(readyIn, spaceIn);

	if (spaceIn <= 0) {
		bufferFullIn = true;
	}
	if (inPositionBufferIn == 0) {
		bufferEmptyIn = true;
	}

	if (!bufferFullIn) {
		for (auto k = 0; k < process; k++) {
			t_message message;
			inputSignals[1]->bufferGet(&message);
			t_message_field messageField = message.at(k);

			string messageFieldName = messageField.fieldName;
			string messageFieldValue = messageField.fieldValue;

			for (unsigned l = 0; l < messageFieldValue.length(); l++) {
				pBufferIn[inPositionBufferIn] = (int)messageFieldValue.at(l);
				inPositionBufferIn++;
			}
		}
		bufferEmptyIn = false;
	}

	/*Message available to be processed*/
	int readyIn2 = inputSignals[0]->ready();

	int spaceOut = spaceBufferOut();
	spaceOut = (int)floor(spaceOut / messageDataLength);
	int processOut = min(readyIn2, spaceOut);

	if (spaceOut <= 0) {
		bufferFullOut = true;
	}

	if (outPositionBufferOut == 0) {
		bufferEmptyOut = true;
	}

	if ((processOut > 0) && (!bufferFullOut)) {
		for (auto m = 0; m < messageDataLength; m++) {
			pBufferOut[outPositionBufferOut] = pBufferIn[inPositionBufferOut];
			outPositionBufferOut++;
			inPositionBufferIn--;
		}
		bufferEmptyOut = false;
	}

	return true;
}

int MessageProcessorAlice::spaceBufferIn() {

	if (bufferFullIn) return 0;
	if (inPositionBufferIn == outPositionBufferIn) return bufferLengthIn;
	if (inPositionBufferIn < outPositionBufferIn) return (outPositionBufferIn - inPositionBufferIn);
	if (outPositionBufferIn >= 0) return (bufferLengthIn - inPositionBufferIn + outPositionBufferIn);
	if (outPositionBufferIn == -1) return (bufferLengthIn - inPositionBufferIn);
	return -1;

};

int MessageProcessorAlice::spaceBufferOut() {

	if (bufferFullOut) return 0;
	if (inPositionBufferOut == outPositionBufferOut) return bufferLengthOut;
	if (inPositionBufferOut < outPositionBufferOut) return (outPositionBufferOut - inPositionBufferOut);
	if (outPositionBufferOut >= 0) return (bufferLengthOut - inPositionBufferOut + outPositionBufferOut);
	if (outPositionBufferOut == -1) return (bufferLengthOut - inPositionBufferOut);
	return -1;

};
