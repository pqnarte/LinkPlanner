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

	processStoredMessages();
	processInMessages(readyBasisIn);
	processStoredMessages();
	

	return true;
}

bool MessageProcessorAlice::processStoredMessages() {
	if (storedMessages.size() == 0) 
		storedMessageEmpty = true;
	else
		storedMessageEmpty = false;


	if (!storedMessageEmpty) {
		t_message_type mType = getMessageType(storedMessages[0]);
		t_message_data_length mDataLength = getMessageDataLength(storedMessages[0]);
		t_message_data mData = getMessageData(storedMessages[0], mDataLength);

		string mDataOut;
		switch (mType)
		{
		case BasisReconciliation:
			for (auto k = 0; k < mDataLength; k++) {
				t_binary inBit;
				inputSignals[0]->bufferGet(&inBit);

				if (inBit == mData[k]) {
					outputSignals[0]->bufferPut((t_binary)1);
					mDataOut.append("1");
				}
				else {
					outputSignals[0]->bufferPut((t_binary)0);
					mDataOut.append("0");
				}
			}
			break;
		default:
			break;
		}
		

		storedMessages.erase(storedMessages.begin() + nextMessage); // Removes from the vector the message processed 

		t_message mToSend;
		mToSend.messageData = mDataOut;
		mToSend.messageDataLenght = to_string(mDataOut.size());
		mToSend.messageType = mType;

		outputSignals[1]->bufferPut((t_message)mToSend);

		return true;
	}

	else
		return false;
}

bool MessageProcessorAlice::processInMessages(int readyInBits) {
	t_message mReceived;
	inputSignals[1]->bufferGet(&mReceived);
	t_message_type mType = getMessageType(mReceived);
	t_message_data_length mDataLength = getMessageDataLength(mReceived);
	t_message_data mData = getMessageData(mReceived, mDataLength);


	if (readyInBits >= mDataLength) {
		string mDataOut;
		switch (mType)
		{
		case BasisReconciliation:
			for (auto k = 0; k < mDataLength; k++) {
				t_binary inBits;
				inputSignals[0]->bufferGet(&inBits);
				if (inBits == mData[k]) {
					outputSignals[0]->bufferPut((t_binary)1);
					mDataOut.append("1");
				}
				else {
					outputSignals[0]->bufferPut((t_binary)0);
					mDataOut.append("0");
				}
			}
			break;
		default:
			break;
		}
		
		t_message mToSend;
		mToSend.messageType = mType;
		mToSend.messageDataLenght = to_string(mDataOut.size());
		mToSend.messageData = mDataOut;

		outputSignals[1]->bufferPut((t_message)mToSend);

		return true;
	}
	else {
		storedMessages[nextMessage] = mReceived;
		nextMessage++;
		nextMessage = nextMessage % storedMessages.size();
	}
	return false;
}

t_message_type MessageProcessorAlice::getMessageType(const t_message& msg) {

	if ((msg.messageType).compare("BasisReconcilitation")==0) return BasisReconciliation;
}

t_message_data_length MessageProcessorAlice::getMessageDataLength(const t_message& msg) {

	return stoi(msg.messageDataLenght);
}


t_message_data MessageProcessorAlice::getMessageData(const t_message& msg, t_message_data_length dataLength) {

	string mDataString = msg.messageData;

	vector <int> mDataVector;

	for (auto k = 0; k < dataLength; k++) {
		mDataVector[0] = (int)mDataString.at(k);
	}

	return mDataVector;
}

