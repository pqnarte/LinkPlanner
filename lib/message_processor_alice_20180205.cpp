
#include "message_processor_alice_20180205.h"



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

	int readyMessageIn = inputSignals[1]->ready();
	int readyBasisIn = inputSignals[0]->ready();

	int spaceBasisOut = outputSignals[0]->space();
	int spaceMessageOut = outputSignals[1]->space();

	int ready = min(readyMessageIn, readyBasisIn);
	int space = min(spaceBasisOut, spaceMessageOut);

	int process = min(ready, space);

	if (process <= 0) return false;

	for (auto k = 0; k < process; k++) {
		t_message messageIn;
		inputSignals[1]->bufferGet(&messageIn);
		stateProcessor = ProcessMessageIn;

		t_message_field mToProcess;
		t_message_field mOut;
		t_message mToSend;
		string mDataIn;
		string mDataOut;

		switch (stateProcessor)
		{
		case ProcessMessageIn:
			mToProcess = messageIn.at(k);
			mDataIn = mToProcess.fieldValue;
		
			messageDataLength = stoi(mToProcess.fieldName);
			messageType = MessageTypeConvert(mToProcess.fieldName);

			stateProcessor = ProcessData;
			break;

		case ProcessData:
			if (messageType = BasisReconciliation) {
				t_binary BasisIn;
				for (auto m = 0; m < messageDataLength; m++) {
					inputSignals[0]->bufferGet(&BasisIn);

					if (BasisIn == (int)mDataIn.at(m)) {
						outputSignals[0]->bufferPut((t_binary)1);
						mDataOut.append(to_string(1));
					}
					else {
						outputSignals[0]->bufferPut((t_binary)0);
						mDataOut.append(to_string(0));
					}
				}

				stateProcessor = MessageToSend;
			}
			break;

		case MessageToSend:
			
			mOut.fieldDataLenght = to_string(mDataOut.size());
			mOut.fieldName = messageType;
			mOut.fieldValue = mDataOut;
			
			mToSend = {mOut};

			outputSignals[1]->bufferPut((t_message) mToSend);

			stateProcessor = StandBy;
			break;

		case StandBy:
			break;

		default:
			break;
		}
		
	}

	return true;
}



message_value_type MessageProcessorAlice::MessageTypeConvert(const string& str) {

	if (str == "BasisReconcilitation") return BasisReconciliation;
	else
		return Empty;
}
