# ifndef FILTER_H_
# define FILTER_H_
# include <vector>
# include "netxpto.h"

class FilterRoot : public Block {

public:
	vector<t_real> impulseResponse;
	vector<t_complex> transferFunction;
	int impulseResponseLength; 
	int transferFunctionLength;
	string filterDomain; 
	
	
	/* Methods */
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
	
	/*TIME */
	vector<t_real> delayLine;
	bool saveImpulseResponse{ true };
	string impulseResponseFilename{ "impulse_response.imp" };
	bool seeBeginningOfImpulseResponse{ true }; 
	
	/*FREQ */
	vector<t_complex> previousCopy;
	int K{ 0 };
	bool saveTransferFunction{ true };
	string transferFunctionFilename{ "transfer_function.tfn" };
	bool seeBeginningOfTransferFunction{ true };
	
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// pulseShaper /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
enum PulseShaperFilter { RaisedCosine, Gaussian, Square };

class PulseShaper : public FilterRoot
{
	/* Input Parameters */
	PulseShaperFilter filterType{ RaisedCosine };
	int impulseResponseTimeLength{ 16 };		// in units of symbol period
	double rollOffFactor{ 0.9 };				// Roll-off factor
	bool passiveFilterMode{ false };
	string filterDomainType{ "time" };

public:

	/* Methods */
	PulseShaper() :FilterRoot() {};
	PulseShaper(vector<Signal *> &InputSig, vector<Signal *> OutputSig) :FilterRoot(InputSig, OutputSig) {};

	void initialize(void);

	void setImpulseResponseTimeLength(int impResponseTimeLength) { impulseResponseTimeLength = impResponseTimeLength; };
	int const getImpulseResponseTimeLength(void) { return impulseResponseTimeLength; };

	void setFilterType(PulseShaperFilter fType) { filterType = fType; };
	PulseShaperFilter const getFilterType(void) { return filterType; };

	void setRollOffFactor(double rOffFactor) { rollOffFactor = rOffFactor; };
	double const getRollOffFactor() { return rollOffFactor; };

	void usePassiveFilterMode(bool pFilterMode) { passiveFilterMode = pFilterMode; };

	void setFilterDomainType(string fDomain) { filterDomainType = fDomain; };
	string getFilterDomainType() { return filterDomainType; };
};
#endif

