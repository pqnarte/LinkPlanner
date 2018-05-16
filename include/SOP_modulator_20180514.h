#ifndef SOP_MODULATOR_H
#define SOP_MODULATOR_H

#include "netxpto_20180118.h"
#include <math.h> 
#include <random>
#include <chrono>


class SOPModulator : public Block {
	/*Input parameters*/
	
	long double delta_p{ 60e-4 };						// Polarization linewidth 
	double mean{ 0.0 };
	double tSymbolPeriod{ 0.0 };						// symbol interval
	

	/*Internal parameters*/
	std::default_random_engine generator;
	vector<double>alpha = { 0.0, 0.0, 0.0 };
	vector<double>aa = { 0.0, 0.0, 0.0 };

	/*State variables*/
	bool firstSop{ true };
	vector< vector<t_complex> > JJnext = { {0,0},{0,0} };
	vector< vector<t_complex> > JJ = { { 0,0 },{ 0,0 } };
public:

	/*Methods*/
	SOPModulator() {};
	SOPModulator(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) :Block(InputSig, OutputSig) {};

	void initialize(void);
	bool runBlock(void);

	void setDeltaP(long double deltaP) { delta_p = deltaP; };
	long double getDeltaP() { return delta_p; };

};

#endif // !SOP_MODULATOR_H
