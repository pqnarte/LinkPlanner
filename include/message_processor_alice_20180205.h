#ifndef MESSAGE_INTERFACE_H
#define MESSAGE_INTERFACE_H

#include <math.h>
#include <string.h>

#include "netxpto_20180118.h"

enum message_value_type{ BasisReconciliation, Empty };
enum state_block { ProcessMessageIn, ProcessData, MessageToSend, StandBy};

class MessageProcessorAlice : public Block {

	/*Input Parameters*/


	/*State Variables*/
	message_value_type messageType{ BasisReconciliation };
	state_block stateProcessor{ ProcessMessageIn };
	int messageDataLength{ 64 };



public:


	/*Methods*/
	MessageProcessorAlice() {};
	MessageProcessorAlice(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals) : Block(inputSignals, outputSignals) {};

	message_value_type MessageTypeConvert(const string& str);

	void initialize(void);
	bool runBlock(void);
};


#endif
