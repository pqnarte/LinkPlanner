#include "netxpto.h"
#include "message_interface.h"

void MessageInterface::initialize(void) {
	outputSignals[0]->samplingPeriod = inputSignals[0]->samplingPeriod;
	outputSignals[0]->symbolPeriod = inputSignals[0]->symbolPeriod;
	outputSignals[0]->samplesPerSymbol = inputSignals[0]->samplesPerSymbol;
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());

	outputSignals[1]->samplingPeriod = inputSignals[1]->samplingPeriod;
	outputSignals[1]->symbolPeriod = inputSignals[1]->symbolPeriod;
	outputSignals[1]->samplesPerSymbol = inputSignals[1]->samplesPerSymbol;
	outputSignals[1]->setFirstValueToBeSaved(inputSignals[1]->getFirstValueToBeSaved());
}

bool MessageInterface::runBlock(void) {

	const int enableToWrite = 0;
	const int enableToRead = 1;
	const int bitsToProcess = 2;
	const int idleState = 3;

	/*Data to read from message*/
	int ready1 = inputSignals[1]->ready();
	/*Data to Process from binary source*/
	int ready2 = inputSignals[0]->ready();
	/*State Variable set*/
	StateMachine = idleState;

	bool alive = false;

	/*While there are bits to process from binary source*/
	while (ready2 != 0) {
		if (ready1 != 0) {
			int mType;
			int emptySpace;

			int space1 = outputSignals[0]->space();
			int space2 = outputSignals[1]->space();

			int length = min(space1, space2);

			if (length <= 0) return false;

			switch (StateMachine) {
				case enableToWrite:
					int auxIn;
					for (int i = 0; i < dataLength; i++) {
						inputSignals[1]->bufferGet(&auxIn);
						pBufferIn[i] = auxIn;
						bIn++;
					}
					newMessage = true;
					StateMachine = idleState;
					break;

				case enableToRead:
					for (bOut = 0; bOut <= bufferLength; bOut++) {
						pBufferOut[bOut] = pBufferIn[bOut];
					}
					StateMachine = bitsToProcess;
					break;

				case bitsToProcess:
					int auxBitsOut;

					while (bIn != 0)
					{
						outputSignals[1]->bufferPut(mType);
						outputSignals[1]->bufferPut(dataLength);

						for (bOut = 0; bOut <= dataLength; bOut++) {
							inputSignals[0]->bufferGet(&auxBitsOut);
							if (pBufferOut[bOut] == 0 || pBufferOut[bOut] == 1) {
								if (pBufferOut[bOut] == auxBitsOut) {
									outputSignals[0]->bufferPut(pBufferOut[bOut]);
									outputSignals[1]->bufferPut(pBufferOut[bOut]);
								}
							}
							else {
								outputSignals[1]->bufferPut(pBufferOut[bOut]);
							}
							bIn--;
						}
					}
					StateMachine = idleState;
					break;

				case idleState:
					emptySpace = bufferLength - bIn;
					if (newMessage == true)
					{
						inputSignals[1]->bufferGet(&mType);
						inputSignals[1]->bufferGet(&dataLength);
						newMessage = false;

						if (mType == basisReconciliation) {
							if (emptySpace >= dataLength) {
								StateMachine = enableToWrite;
							}
							else {
								if (bIn == bufferLength) {
									StateMachine = enableToRead;
								}
							}

						}

					}
					else
						alive = true;

					break;
			}
		}
	}
	
	
	return alive;
}