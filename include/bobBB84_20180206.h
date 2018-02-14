#ifndef bobBB84_H
#define bobBB84_H

#include "netxpto_20180118.h"

typedef int t_message_data_length;
typedef string t_message_data;
typedef enum { BasisReconciliation } t_message_type;

class bobBB84 : public Block {

	/*Input Parameters*/
	int messageDataLength{ 64 };

public:

	bobBB84() {};
	bobBB84(vector<Signal *> &inputSignals, vector<Signal *> &outputSignals) : Block(inputSignals, outputSignals) {};

	void initialize(void);

	bool runBlock(void);

	void setMessageDataLength(t_message msg, t_message_data_length mDLength) { msg.messageDataLength = to_string(mDLength); };

	void setMessageData(t_message msg, t_message_data mData) { msg.messageData = mData; };

	void setMessageType(t_message msg, t_message_type mType) { msg.messageType = mType; };


};

#endif // !bobBB84_H

