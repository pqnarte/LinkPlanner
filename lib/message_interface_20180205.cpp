
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
	int readyMessageIn = inputSignals[1]->ready();

	int spaceMesassageIn = spaceBufferIn();							//in units of bits
	spaceIn = (int) floor(spaceIn / messageDataLength);		//in units of messages

	int process = min(readyMessageIn, spaceIn);

	if (spaceIn <= 0) {
		bufferFullIn = true;
	}
	if (spaceIn == (bufferLengthIn/messageDataLength)) {
		bufferEmptyIn = true;
	}

	if ((bufferFullIn == false) && (process > 0)) {
		for (auto k = 0; k < process; k++) {
			t_message message;
			inputSignals[1]->bufferGet(&message);
			t_message_field messageField = message.at(k);

			string messageFieldName = messageField.fieldName;
			messageType = MessageTypeConvert(messageFieldName);
			string messageFieldValue = messageField.fieldValue;

			for (unsigned l = 0; l < messageFieldValue.length(); l++) {
				pBufferIn[inPositionBufferIn] = (int) messageFieldValue.at(l);

				inPositionBufferIn++;
				inPositionBufferIn = inPositionBufferIn % bufferLengthIn;
			}
		}
		bufferEmptyIn = false;
	}

	/*Message available to be processed*/
	
	if (bufferEmptyIn == false) {
		int readyBits = inputSignals[0]->ready();
		int spaceBits = outputSignals[0]->space();
		int spaceOut = spaceBufferOut();
		spaceOut = (int) floor(spaceOut / messageDataLength);

		if (spaceOut <= 0) {
			bufferFullOut = true;
		}
		if (spaceOut == (bufferLengthOut * messageDataLength)) {
			bufferEmptyOut = true;
		}

		int space = min(spaceBits, spaceOut);

		int process2 = min(space, readyBits);

		if (process2 > 0) {
			switch (messageType)
			{
			case BasisReconciliation:
				for (auto m = 0; m < messageDataLength; m++) {
					t_binary basis;
					inputSignals[0]->bufferGet(&basis);

					if (basis == pBufferIn[outPositionBufferIn]) {
						outputSignals[0]->bufferPut((t_binary)1);
						pBufferOut[inPositionBufferOut] = 1;
					}
					else {
						outputSignals[0]->bufferPut((t_binary)0);
						pBufferOut[inPositionBufferOut] = 0;
					}

					outPositionBufferIn++;
					outPositionBufferIn = outPositionBufferIn % bufferLengthIn;

					inPositionBufferOut++;
					inPositionBufferOut = inPositionBufferOut % bufferLengthOut;
				}
				bufferEmptyOut = false;
				break;

			default:
				break;
			}
			
		}
	}

	/*MessageToSend*/
	if (bufferEmptyOut == false) {
		string messageOut;

		for (auto n = 0; n < messageDataLength; n++) {
			messageOut.append(to_string(pBufferOut[outPositionBufferOut]));

			outPositionBufferOut++;
			outPositionBufferOut = outPositionBufferOut % bufferLengthOut;
		}

		t_message_field m;
		m.fieldName = messageFieldName;
		m.fieldValue = messageOut;
		
		t_message mOut{ m };

		outputSignals[1]->bufferPut((t_message)mOut);

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

message_value_type MessageProcessorAlice::MessageTypeConvert(const string& str) {

	if (str == "BasisReconcilitation") return BasisReconciliation;

}
