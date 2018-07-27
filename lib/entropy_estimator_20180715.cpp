# include "entropy_estimator_20180715.h"
# include <iostream>
# include <fstream>
# include <numeric>     
#include <math.h> 

using namespace std;

entropy_estimator::entropy_estimator(vector<Signal *> &InputSig, vector<Signal *> &OutputSig) {

	//numberOfInputSignals = (int)InputSig.size();

	inputSignals = InputSig;

	outputSignals = OutputSig;

	nBits = inputSignals[0]->getBufferLength();		// Default
	minWindow = nBits;								// Default

}



bool entropy_estimator::runBlock(void)
{

	int ready = inputSignals[0]->ready();
	int buf_L = inputSignals[0]->getBufferLength();

	int process, N;

	t_binary data;

	if (buf_L < minWindow) {
		n = ceil((double)minWindow / buf_L);				// Window equal to count x buffer length
	}
	else {
		n = 1;												// Window equal to buffer length
	}

	window_size = n * buf_L;								// Size of the window in multiples of buffer length
	static vector<int> h_store(window_size);				// Stores the bits to be processed

	N = nBits / window_size;								// Total number of estimations
	static vector<double> h_entropy(N);						// Vector that stores the estimations

	if (count == n) {										// If the window is filled, the estimation is computed
		h_entropy[count_est] = compute_entropy(h_store, window_size);
		count_est++;										// Counts the estimation number
		count = 0;											// Reset count
	}

	process = ready;
	//if (process == 0 || process < buf_L) {				
	if ((count_est + 1)*window_size > nBits)					// The number of bits defined for analysis was reached
	{
		for (int k = 0; k < ready; k++) {					// Put the remaining data at the output
			(inputSignals[0])->bufferGet(&data);
			(outputSignals[0])->bufferPut(data);
		}

		if (flag == 0) {									// Only executes once
			compute_mean_var(h_entropy);					// Compute mean and var
			print_to_file(h_entropy);						// Print results to file
		}

		flag = 1;
		return false;
	}


	while (count < n) {										// Fills the window with enough data

		p = count * buf_L;

		for (int i = 0; i < buf_L; i++) {

			(inputSignals[0])->bufferGet(&data);
			h_store[i + p] = data;

			(outputSignals[0])->bufferPut(data);			// Data used to compute entropy at output

		}

		count++;											// To check if the window is filled
		return true;
	}

	numberOfSamples = numberOfSamples - process;

}



double entropy_estimator::compute_entropy(vector<int> h_store, int window_size) {

	int n_one = 0;
	double h;

	for (int i = 0; i < window_size; i++) {

		if (h_store[i] == 1) {

			n_one = n_one + 1;
		}
	}

	double p_one = (double)n_one / window_size;

	if (p_one == 1 || p_one == 0)
	{
		h = 0;									// Info theory conv. 0xlog2(0) = 0
	}
	else
	{
		h = (double)-p_one * log2(p_one) - (1 - p_one) * log2(1 - p_one);
	}

	return h;

}


void entropy_estimator::print_to_file(vector<double> &h) {

	ofstream fOut("entropy_est.txt");
	fOut << "-------- Parameters ---------" << "\n";
	fOut << "Total nº of bits analyzed: " << window_size * h.size() << endl;
	fOut << "Window size adjusted to: " << window_size << endl;

	fOut << "\n" << "---------- Results ----------" << "\n";
	fOut << "Entropy Mean = " << m << endl;
	fOut << "Entropy Variance = " << var << "\n" << endl;

	fOut << "Entropy Estimations " << "\n";
	for (const auto &e : h) fOut << e << endl;

	fOut.close();

}

void entropy_estimator::compute_mean_var(vector<double> &h) {

	double sum = 0;
	double sum2 = 0;
	int n0 = h.size();

	// Compute the mean and variance
	for (int i = 0; i < n0; i++) {
		sum = sum + h[i];
		sum2 = sum2 + (h[i] * h[i]);
	}

	m = sum / n0;								// Mean

	var = (sum2 - (sum*sum) / n0) / n0;			// Var

}