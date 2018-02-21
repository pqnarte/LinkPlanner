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
		mDataToSend.append(to_string(data));
	}

	t_message messageOut;
	setMessageDataLength(messageOut, messageDataLength);
	setMessageData(messageOut, mDataToSend);
	setMessageType(messageOut, BasisReconciliation);

	outputSignals[1]->bufferPut((t_message)messageOut);

	return true;
}

bool MessageProcessorBob::ProcessReceivedMessage() {

	
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
