# include "..\include\m_qam_mapper_20180815.h"


void MQamMapper::initialize(void){

	for (auto k{ 0 }; k != numberOfOutputSignals; ++k)
	{
		outputSignals[0]->setSymbolPeriod(log2(m) * inputSignals[0]->getSymbolPeriod());
		outputSignals[0]->setSamplingPeriod(log2(m) * inputSignals[0]->getSamplingPeriod());
		outputSignals[0]->setSamplesPerSymbol(1);
		outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
	}

}

bool MQamMapper::runBlock(void) {

	auto ready = inputSignals[0]->ready();

	auto space = outputSignals[0]->space();
	if (numberOfOutputSignals == 2)
	{
		space = (space < outputSignals[1]->space()) ? space : outputSignals[1]->space();
	}

	auto length = (ready <= (2 * space)) ? ready : space; // equivalent to min(ready, 2 * space);

	if (length <= 0) return false;

	t_binary binaryValue;
	int nBinaryValues = (int)log2(m);
	for (auto k{ 0 }; k!=length; ++k) {

		inputSignals[0]->bufferGet(&binaryValue);
		auxSignalNumber = auxSignalNumber + (int) pow(2, nBinaryValues - 1 - auxBinaryValue) * binaryValue;
		auxBinaryValue++;

		if (auxBinaryValue == nBinaryValues) {

			t_real auxI = iqAmplitudes[auxSignalNumber].real();
			outputSignals[0]->bufferPut((t_real)auxI);
			
			
			if (numberOfOutputSignals == 2)
			{
				t_real auxQ = iqAmplitudes[auxSignalNumber].imag();
				outputSignals[1]->bufferPut((t_real)auxQ);
			}

			auxBinaryValue = 0;
			auxSignalNumber = 0;
		}
	}

	return true;
}

void MQamMapper::setIqAmplitudes(vector<t_iqValues> iqAmplitudesValues){
	m = (int) iqAmplitudesValues.size();
	iqAmplitudes.resize(m);
	iqAmplitudes = iqAmplitudesValues; 
};

void MQamMapper::setM(int mValue){
	m = mValue;

	iqAmplitudes.resize(m);
	switch (m) {
	case 4:
		iqAmplitudes = { { 1.0, 1.0 }, { -1.0, 1.0 }, { -1.0, -1.0 }, { 1.0, -1.0 } };

	case 16:
		iqAmplitudes = { { -3.0, -3.0 },{ -3.0, -1.0 },{ -3.0, 3.0 },{ -3.0, 1.0 },{ -1.0, -3.0 },{ -1.0, -1.0 },{ -1.0, 3.0 },{ -1.0, 1.0 },{ 3.0, -3.0 },{ 3.0, -1.0 }, { 3.0, 3.0 },{ 3.0, 1.0 },{ 1.0, -3.0 },{ 1.0, -1.0 },{ 1.0, 3.0 },{ 1.0, 1.0 } };
	};
}; 
