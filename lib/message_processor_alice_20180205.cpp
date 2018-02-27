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

	bool alive{ false };

	do {
		alive = processStoredMessages();
		alive = alive || processInMessages();
	} while (alive);

	return alive;
}

bool MessageProcessorAlice::processStoredMessages() {

	bool alive{ false };

	int n{ 0 };

	do {
	
		t_message_type mType = getMessageType(storedMessages[n]);
		t_message_data_length mDataLength = getMessageDataLength(storedMessages[n]);
		t_message_data mData = getMessageData(storedMessages[n], mDataLength);

		string mDataOut{""};
		int process{ 0 };
		switch (mType) {

			case BasisReconciliation:

				int ready = min(inputSignals[0]->ready(), mDataLength);
				ready = min(ready, outputSignals[0]->space());
				process = min(ready, getMaxMessageDataLength());

				for (auto k = 0; k < process; k++) {

					alive = true;

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
		}

		int dLength = mDataLength - process;
		if (dLength == 0) {
			storedMessages.erase(storedMessages.begin()+n);
			numberOfStoredMessages= storedMessages.size();
			n--;
		}
		setMessageDataLength(storedMessages[n], dLength);

		mData.erase(mData.begin(), mData.begin() + process);
		string mDataUpdated{ "" };
		for (unsigned int m = 0; m < mData.size(); m++) {
			mDataUpdated.append(to_string(mData[m]));
		}
		setMessageData(storedMessages[n], mDataUpdated);

		t_message messageOut;
		setMessageType(messageOut, mType);
		setMessageDataLength(messageOut, mDataOut.size());
		setMessageData(messageOut, mDataOut);
		outputSignals[1]->bufferPut((t_message) messageOut);
	    
		n++;

	} while (n <= numberOfStoredMessages);

	return alive;
}


bool MessageProcessorAlice::processInMessages() {

	bool alive{ false };

	if (numberOfStoredMessages < maxNumberOfStoredMessages) {
		inputSignals[1]->bufferGet(&storedMessages[numberOfStoredMessages]);
		numberOfStoredMessages++;
		alive = true;
	}

	return alive;

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

