#ifndef MESSAGE_INTERFACE_H
#define MESSAGE_INTERFACE_H

#include <math.h>
#include <string.h>

#include "netxpto_20180118.h"

typedef enum { BasisReconciliation } t_message_type;
typedef int t_message_data_length;
typedef vector<int> t_message_data;

enum state_block { ProcessMessageIn, ProcessData, MessageToSend, StandBy};

class MessageProcessorAlice : public Block {

public:

	/*Public Methods*/
	MessageProcessorAlice() {};
	MessageProcessorAlice(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals) : Block(inputSignals, outputSignals) {};

	void initialize(void);
	bool runBlock(void);

	void setMaxMessageDataLength(t_message_data_length maxDataLength) { maxMessageDataLength = maxDataLength; };
	t_message_data_length getMaxMessageDataLength() { return maxMessageDataLength; };


private:

	/*Input Parameters*/
	t_message_data_length maxMessageDataLength{ 64 };

	/*State Variables*/
	state_block stateProcessor{ ProcessMessageIn };

	vector<t_message> storedMessages;
	bool storedMessageEmpty{ true };
	int nextMessage{ 0 };

	/*Private Methods*/
	t_message_type getMessageType(const t_message& msg);
	void setMessageType(t_message msg, t_message_type mType) { msg.messageType = mType; };
	t_message_data_length getMessageDataLength(const t_message& msg);
	void setMessageDataLength(t_message msg, t_message_data_length mDataLength) { msg.messageDataLength = mDataLength; };
	t_message_data getMessageData(const t_message& msg, t_message_data_length dataLength);
	void setMessageData(t_message msg, string mData) { msg.messageData = mData; };



	bool processStoredMessages();
	bool processInMessages();
};


#endif
