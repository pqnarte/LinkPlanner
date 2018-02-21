#ifndef MESSAGE_PROCESSOR_BOB_H
#define MESSAGE_PROCESSOR_BOB_H

#include "netxpto_20180118.h"

typedef enum { BasisReconciliation } t_message_type;
typedef int t_message_data_length;
typedef vector<int> t_message_data;

class MessageProcessorBob : public Block {
	
public:
	/*Public Methods*/
	MessageProcessorBob() {};
	MessageProcessorBob(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals) : Block(inputSignals, outputSignals) {};

	void initialize(void);
	bool runBlock(void);

private:
	/*Input Parameters*/
	t_message_data_length messageDataLength{ 64 };

	/*State Variables*/
	vector<t_message> storedMessages;
	int numberOfStoredMessages{ 0 };

	/*Private Methods*/
	t_message_data_length getMessageDataLength(const t_message& msg);
	void setMessageDataLength(t_message msg, t_message_data_length mDataLength) { msg.messageDataLength = mDataLength; };
	t_message_type getMessageType(const t_message& msg);
	void setMessageType(t_message msg, t_message_type mType) { msg.messageType = mType; };
	t_message_data getMessageData(const t_message& msg, t_message_data_length dataLength);
	void setMessageData(t_message msg, string mData) { msg.messageData = mData; };

	bool ProcessMessageToSend();
	bool ProcessReceivedMessage();

};
	
#endif // !MESSAGE_PROCESSOR_BOB_H

