#include "message_processor_bob_20180221.h"

void MessageProcessorBob::initialize(void) {

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[1]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[1]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[1]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[1]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

}

bool MessageProcessorBob::runBlock(void) {
	bool alive{ false };

	do {
		alive = ProcessMessageToSend();
		alive = alive || ProcessReceivedMessage();
		alive = alive || ProcessStoredMessage();
	} while (alive);

	return alive;
}

bool MessageProcessorBob::ProcessMessageToSend() {

	int ready = min(inputSignals[0]->ready(), messageDataLength);
	int space = outputSignals[1]->space();
	int process = min(ready, space);

	if (process <= 0) return false;

	string mDataToSend{ "" };
	for (auto k = 0; k < messageDataLength; k++) {
		t_real data;
		inputSignals[0]->bufferGet(&data);
		mDataToSend = mDataToSend.append(to_string((int)data));
	}

	t_message messageOut;
	messageOut.messageDataLength = to_string(messageDataLength);
	messageOut.messageData = mDataToSend;
//	setMessageDataLength(messageOut,messageDataLength);
//	setMessageData(messageOut, mDataToSend);
//	setMessageType(messageOut, BasisReconciliation);

	outputSignals[1]->bufferPut((t_message)messageOut);

	return true;
}

bool MessageProcessorBob::ProcessReceivedMessage() {

	bool alive{ false };

	int ready = inputSignals[1]->ready();
	if (ready <= 0);
	else {
		if (numberOfStoredMessages < maxNumberOfStoredMessages) {
			inputSignals[1]->bufferGet(&storedMessages[numberOfStoredMessages]);
			numberOfStoredMessages++;
			alive = true;
		}
	}
	return alive;
}

bool MessageProcessorBob::ProcessStoredMessage() {

	bool alive{ false };

	int n{ 0 };
	if (storedMessages.size() > 0) {
		do {

			t_message_type mType = getMessageType(storedMessages[n]);
			t_message_data_length mDataLength = getMessageDataLength(storedMessages[n]);
			t_message_data mData = getMessageData(storedMessages[n], mDataLength);

			string mDataOut{ "" };
			int process{ 0 };
			switch (mType) {

			case BasisReconciliation:
				process = min(outputSignals[0]->space(), mDataLength);

				for (auto k = 0; k < process; k++) {

					alive = true;
					outputSignals[0]->bufferPut((t_real)mData[k]);

				}
				break;
			}

			int dLength = mDataLength - process;
			if (dLength == 0) {
				storedMessages.erase(storedMessages.begin() + n);
				numberOfStoredMessages = storedMessages.size();
				n--;
			}
			setMessageDataLength(storedMessages[n], dLength);

			mData.erase(mData.begin(), mData.begin() + process);
			string mDataUpdated{ "" };
			for (unsigned int m = 0; m < mData.size(); m++) {
				mDataUpdated.append(to_string(mData[m]));
			}
			setMessageData(storedMessages[n], mDataUpdated);

			n++;

		} while (n <= numberOfStoredMessages);
	}
	

	return alive;
}

t_message_data MessageProcessorBob::getMessageData(const t_message& msg, t_message_data_length dataLength) {
	string mDataString = msg.messageData;

	vector <int> mDataVector;

	for (auto k = 0; k < dataLength; k++) {
		mDataVector[0] = (int)mDataString.at(k);
	}

	return mDataVector;
}

t_message_data_length MessageProcessorBob::getMessageDataLength(const t_message& msg) {
	return stoi(msg.messageDataLength);
}

t_message_type MessageProcessorBob::getMessageType(const t_message& msg) {
	if ((msg.messageType).compare("BasisReconcilitation") == 0) return BasisReconciliation;

	return (t_message_type)0;
}
