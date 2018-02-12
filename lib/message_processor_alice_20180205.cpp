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

	bool alive = processStoredMessages();
	alive = alive || processInMessages();
	alive = alive || processStoredMessages();
	

	return alive;
}

bool MessageProcessorAlice::processStoredMessages() {

	if (storedMessageEmpty || (outputSignals[1]->space() == 0))
		return false;
	else {
		
		t_message_type mType = getMessageType(storedMessages[nextMessage]);
		t_message_data_length mDataLength = getMessageDataLength(storedMessages[nextMessage]);
		t_message_data mData = getMessageData(storedMessages[nextMessage], mDataLength);

		string mDataOut{""};
		string mDataUpdated{ "" };
		switch (mType) {
			case BasisReconciliation:

				int ready = min(inputSignals[0]->ready(), mDataLength);
				int process = min(ready, getMaxMessageDataLength());

				for (auto k = 0; k < process; k++) {
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
				setMessageDataLength(storedMessages[nextMessage], mDataLength - process);
				mData.erase(mData.begin(), mData.begin() + process);
				
				for (unsigned int m = 0; m < mData.size(); m++) {
					mDataUpdated.append(to_string(mData[m]));
				}
				setMessageData(storedMessages[nextMessage],mDataUpdated);

				if (stoi(storedMessages[nextMessage].messageDataLength) == 0) {
					nextMessage++;
					nextMessage = nextMessage % storedMessages.capacity();
					sendMessage = true;
				}

				break;
		
		}
		
		if (sendMessage) {
			t_message mToSend;
			mToSend.messageData = mDataOut;
			mToSend.messageDataLength = to_string(mDataOut.size());
			mToSend.messageType = mType;

			outputSignals[1]->bufferPut((t_message)mToSend);
			sendMessage = false;
		}
		
	}

	return true;
}

bool MessageProcessorAlice::processInMessages() {
	t_message mReceived;
	inputSignals[1]->bufferGet(&mReceived);
	t_message_type mType = getMessageType(mReceived);
	t_message_data_length mDataLength = getMessageDataLength(mReceived);
	t_message_data mData = getMessageData(mReceived, mDataLength);

	int readyInBits = inputSignals[0]->ready();
	int spaceMessageOut = outputSignals[1]->space();

	if ((readyInBits >= mDataLength) && (spaceMessageOut > 0)) {
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
		mToSend.messageDataLength = to_string(mDataOut.size());
		mToSend.messageData = mDataOut;

		outputSignals[1]->bufferPut((t_message)mToSend);

		return true;
	}
	else {
		storedMessages[nextMessageIn] = mReceived;
		nextMessageIn++;
		nextMessageIn = nextMessageIn % storedMessages.capacity();
		
		return false;
	}
	
}

t_message_type MessageProcessorAlice::getMessageType(const t_message& msg) {

	if ((msg.messageType).compare("BasisReconcilitation")==0) return BasisReconciliation;

	return (t_message_type) 0;
}

t_message_data_length MessageProcessorAlice::getMessageDataLength(const t_message& msg) {

	return stoi(msg.messageDataLength);
}


t_message_data MessageProcessorAlice::getMessageData(const t_message& msg, t_message_data_length dataLength) {

	string mDataString = msg.messageData;

	vector <int> mDataVector;

	for (auto k = 0; k < dataLength; k++) {
		mDataVector[0] = (int)mDataString.at(k);
	}

	return mDataVector;
}

