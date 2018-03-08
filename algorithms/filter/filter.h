# ifndef FILTER_H_
# define FILTER_H_
# include <vector>
# include "netxpto.h"


/*
class FilterRoot : public Block {

public:

	// Methods 
	FilterRoot() {};
	FilterRoot(vector<Signal *> &InputSig, vector<Signal *> OutputSig) :Block(InputSig, OutputSig) {};

	void initializeFilterRoot(void);
	bool runBlock(void);
	void terminate(void) {};

	void setSaveImpulseResponse(bool sImpulseResponse) { saveImpulseResponse = sImpulseResponse; }; // saveImpulseResponse
	bool getSaveImpulseResponse(void) { return saveImpulseResponse; };

	void setSeeBeginningOfImpulseResponse(bool sBeginning) { seeBeginningOfImpulseResponse = sBeginning; }; // seeBeginningOfImpulseResponse
	bool const getSeeBeginningOfImpulseResponse() { return seeBeginningOfImpulseResponse; };


	void setSaveTransferFunction(bool sTransferFunction) { saveTransferFunction = sTransferFunction; }; // saveTransferFunction
	bool getSaveTransferFunction(void) { return saveTransferFunction; };

	void setSeeBeginningOfTransferFunction(bool sBeginning) { seeBeginningOfTransferFunction = sBeginning; }; // seeBeginningOfTransferFunction
	bool const getSeeBeginningOfTransferFunction() { return seeBeginningOfTransferFunction; };


	void setImpulseResponseLength(int iResponseLength) { impulseResponseLength = iResponseLength; }; // impulseResponseLength
	int const getImpulseResponseLength() { return impulseResponseLength; }

	void setTransferFunctionLength(int iTransferFunctionLength) { transferFunctionLength = iTransferFunctionLength; }; // transferFunctionLength
	int const getTransferFunctionLength() { return transferFunctionLength; };

private:
	
	vector<t_real> impulseResponse;
	int impulseResponseLength;
	bool saveImpulseResponse{ true };
	string impulseResponseFilename{ "impulse_response.imp" };
	bool seeBeginningOfImpulseResponse{ true };

	vector<t_complex> transferFunction;
	int transferFunctionLength;
	bool saveTransferFunction{ true };
	string transferFunctionFilename{ "transfer_function.tfn" };
	bool seeBeginningOfTransferFunction{ true };

	string filterDomain;


	//FREQ 
	vector<t_complex> previousCopy;
	int K{ 0 };
	

	
};
*/


class FIR_Filter : public Block {

public:

	FIR_Filter() {};
	FIR_Filter(vector<Signal *> &InputSig, vector<Signal *> OutputSig) :Block(InputSig, OutputSig) {};

	void initializeFIR_Filter(void);

	bool runBlock(void);

	void terminate(void) {};

	void setSaveImpulseResponse(bool sImpulseResponse) { saveImpulseResponse = sImpulseResponse; };
	bool getSaveImpulseResponse(void) { return saveImpulseResponse; };

	void setImpulseResponseLength(int iResponseLength) { impulseResponseLength = iResponseLength; };
	int const getImpulseResponseLength() { return impulseResponseLength; }

	void setSeeBeginningOfImpulseResponse(bool sBeginning) { seeBeginningOfImpulseResponse = sBeginning; };
	bool const getSeeBeginningOfImpulseResponse() { return seeBeginningOfImpulseResponse; };

private:

	// State Variable 
	vector<t_real> impulseResponse;
	vector<t_real> delayLine;

	/* Input Parameters */
	int impulseResponseLength;							// filter order + 1 (filter order = number of delays)
	bool saveImpulseResponse{ true };
	string impulseResponseFilename{ "impulse_response.imp" };
	bool seeBeginningOfImpulseResponse{ true };


};


class FD_Filter : public Block {

	/* State Variable */

	vector<t_real> inputBufferTimeDomain;
	vector<t_real> outputBufferTimeDomain;

	int inputBufferPointer{ 0 };
	int outputBufferPointer{ 0 };

	/* Input Parameters */
	bool saveTransferFunction{ true };
	string transferFunctionFilename{ "transfer_function.tfn" };
	int transferFunctionLength{ 128 };

	int inputBufferTimeDomainLength{ transferFunctionLength };
	int outputBufferTimeDomainLength{ transferFunctionLength };

public:
	/* State Variable */
	vector<t_complex> transferFunction;

	/* Methods */
	FD_Filter() {};
	FD_Filter(vector<Signal *> &InputSig, vector<Signal *> OutputSig) :Block(InputSig, OutputSig) {};

	void initializeFD_Filter(void);

	bool runBlock(void);

	void terminate(void) {};

	void setInputBufferTimeDomainLength(int iBufferTimeDomainLength) { inputBufferTimeDomainLength = iBufferTimeDomainLength; };
	int const getInputBufferTimeDomainLength() { return inputBufferTimeDomainLength; }

	void setOutputBufferTimeDomainLength(int oBufferTimeDomainLength) { outputBufferTimeDomainLength = oBufferTimeDomainLength; };
	int const getOutputBufferTimeDomainLength() { return outputBufferTimeDomainLength; }

	void setInputBufferPointer(int iBufferPointer) { inputBufferPointer = iBufferPointer; };
	int const getInputBufferPointer() { return inputBufferPointer; }

	void setOutputBufferPointer(int oBufferPointer) { outputBufferPointer = oBufferPointer; };
	int const getOutputBufferPointer() { return outputBufferPointer; }

	void setSaveTransferFunction(bool sTransferFunction) { saveTransferFunction = sTransferFunction; };
	bool getSaveTransferFunction(void) { return saveTransferFunction; };

	void setTransferFunctionLength(int iTransferFunctionLength) { transferFunctionLength = iTransferFunctionLength; };
	int const getTransferFunctionLength() { return transferFunctionLength; };

};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////// pulseShaper /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/*enum PulseShaperFilter { RaisedCosine, Gaussian, Square, RaisedCosineTfn, GaussianTfn, SquareTfn};

class PulseShaper : public FilterRoot
{
	// Input Parameters 
	PulseShaperFilter filterType{ RaisedCosine };
	int impulseResponseTimeLength{ 16 };		// in units of symbol period
	int transferFunctionFrequencyLength{ 16 };
	double rollOffFactor{ 0.9 };				// Roll-off factor
	bool passiveFilterMode{ false };
	string filterDomainType{ "time" };

public:

	// Methods
	PulseShaper() :FilterRoot() {};
	PulseShaper(vector<Signal *> &InputSig, vector<Signal *> OutputSig) :FilterRoot(InputSig, OutputSig) {};

	void initialize(void);

	void setImpulseResponseTimeLength(int impResponseTimeLength) { impulseResponseTimeLength = impResponseTimeLength; };
	int const getImpulseResponseTimeLength(void) { return impulseResponseTimeLength; };

	void setTransferFunctionFrequencyLength(int transFunctionLength) { transferFunctionFrequencyLength = transFunctionLength; };
	int const getTransferFunctionFrequencyLength(void) { return transferFunctionFrequencyLength; };


	void setFilterType(PulseShaperFilter fType) { filterType = fType; };
	PulseShaperFilter const getFilterType(void) { return filterType; };

	void setRollOffFactor(double rOffFactor) { rollOffFactor = rOffFactor; };
	double const getRollOffFactor() { return rollOffFactor; };

	void usePassiveFilterMode(bool pFilterMode) { passiveFilterMode = pFilterMode; };

	void setFilterDomainType(string fDomain) { filterDomainType = fDomain; };
	string getFilterDomainType() { return filterDomainType; };
};*/
#endif

