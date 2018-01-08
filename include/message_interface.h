#ifndef MESSAGE_INTERFACE_H
#define MESSAGE_INTERFACE_H

#include "netxpto.h"

class MessageInterface : public Block {
	/*State Variables*/
	
	int* pBufferIn = new int[512];
	int* ptrIn = pBufferIn;
	int* pBufferOut = new int[512];
	int* ptrOut = pBufferOut;
	int dataLength{ 64 };
	bool newMessage{ true };
	int StateMachine;

	


public:
	/*Input Parameters*/
	int bufferLength{ 512 };
	int bIn{ 0 };
	int bOut{ 0 };
	
	/*Message types*/
	int basisReconciliation{ 0 };

	/*Methods*/
	MessageInterface() {};
	MessageInterface(vector <Signal*> &inputSignals, vector <Signal*> &outputSignals) : Block(inputSignals, outputSignals) {};

	void initialize(void);
	bool runBlock(void);
};

#endif
