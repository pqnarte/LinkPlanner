#include "SOP_modulator_20180514.h"

void SOPModulator::initialize(void) {
	tSymbolPeriod = inputSignals[0]->getSymbolPeriod();

	outputSignals[0]->setSymbolPeriod(inputSignals[0]->getSymbolPeriod());
	outputSignals[0]->setSamplingPeriod(inputSignals[0]->getSamplingPeriod());
	outputSignals[0]->setSamplesPerSymbol(inputSignals[0]->getSamplesPerSymbol());
	outputSignals[0]->setFirstValueToBeSaved(inputSignals[0]->getFirstValueToBeSaved());
}

bool SOPModulator::runBlock(void) {
	bool alive{ false };

	int ready = inputSignals[0]->ready();
	int space = outputSignals[0]->space();

	int process = min(ready, space);

	if (process <= 0) return alive;

	else {
		t_complex i(0, 1);

		/*Pauli Matrices*/
		vector< vector<t_complex> > sigma1(2, vector<t_complex>(2));
		vector< vector<t_complex> > sigma2(2, vector<t_complex>(2));
		vector< vector<t_complex> > sigma3(2, vector<t_complex>(2));
		sigma1[0][0] = 1.0;
		sigma1[0][1] = 0.0;
		sigma1[1][0] = 0.0;
		sigma1[1][1] = 1.0;
		sigma2[0][0] = 0.0;
		sigma2[0][1] = 1.0;
		sigma2[1][0] = 1.0;
		sigma2[1][1] = 0.0;
		sigma3[0][0] = 0.0;
		sigma3[0][1] = -1i;
		sigma3[1][0] = 1i;
		sigma3[1][1] = 0.0;


		for (auto k = 0; k < process; k++) {
			double sigmaSquare = 2 * PI*delta_p*tSymbolPeriod;
			std::normal_distribution<double>distribution(mean, sqrt(sigmaSquare));
			unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count();
			generator.seed(seed);

			double normAlpha{ 0.0 };
			

			vector< vector<double> > I2(2, vector<double>(2));
			vector< vector<t_complex> > a1sigma1(2, vector<t_complex>(2));
			vector< vector<t_complex> > a2sigma2(2, vector<t_complex>(2));
			vector< vector<t_complex> > a3sigma3(2, vector<t_complex>(2));
			
			I2[0][0] = 1.0;
			I2[0][1] = 0.0;
			I2[1][0] = 0.0;
			I2[1][1] = 1.0;
		
			/*alpha*/
			alpha[0] = distribution(generator);
			alpha[1] = distribution(generator);
			alpha[2] = distribution(generator);

			/*norm(alpha)*/
			
			normAlpha = sqrt(pow(alpha[0], 2) + pow(alpha[1], 2) + pow(alpha[2], 2));

			/*aa - unit vector defining the rotation vector*/
			aa[0] = alpha[0] / normAlpha;
			aa[1] = alpha[1] / normAlpha;
			aa[2] = alpha[2] / normAlpha;

			/*Matrix J = I2*cos(normAlpha) - i*sin(normAlpha)*(a1*sigma1 + a2*sigma2 + a3*sigma3) */
			
			vector< vector<t_complex> > sigma(2, vector<t_complex>(2));
			for (auto line = 0; line < 2; line++) {
				for (auto col = 0; col < 2; col++) {
					a1sigma1[line][col] = aa[0] * sigma1[line][col];
					a2sigma2[line][col] = aa[1] * sigma2[line][col];
					a3sigma3[line][col] = aa[2] * sigma3[line][col];
					sigma[line][col] = a1sigma1[line][col] + a2sigma2[line][col] + a3sigma3[line][col];
				}
			}


			t_complex detsigma = sigma[0][0] * sigma[1][1] - sigma[0][1] * sigma[1][0];
			double det1 = abs(detsigma);
			
			for (auto line = 0; line < 2; line++) {
				for (auto col = 0; col < 2; col++) {
					JJ[line][col] = I2[line][col] * cos(normAlpha) - 1i*sigma[line][col]*sin(normAlpha);
				}
			}
			

			t_complex_xy photonIn;
			inputSignals[0]->bufferGet(&photonIn);
			t_complex valueX = photonIn.x;
			t_complex valueY = photonIn.y;

			t_complex valueXOut, valueYOut;
			vector< vector<t_complex> > JJmult(2, vector<t_complex>(2));
			if (firstSop) {
				valueXOut = valueX * JJ[0][0] + valueX * JJ[0][1];
				valueYOut = valueX * JJ[1][0] + valueY * JJ[1][1];
				firstSop = false;
			}
			
			else {
				t_complex mult = 0;
				
				/*Compute JJ*JJnext*/
				for (auto line = 0; line < 2; line++) {
					for (auto col1 = 0; col1 < 2; col1++) {
						for (auto col2 = 0; col2 < 2; col2++) {
							mult = mult + JJ[line][col2] * JJnext[col2][col1];
						}
						JJmult[line][col1] = mult;
						mult = 0;
					}
				}

				valueXOut = valueX * JJmult[0][0] + valueX * JJmult[0][1];
				valueYOut = valueX * JJmult[1][0] + valueY * JJmult[1][1];

				for (auto line = 0; line < 2; line++) {
					for (auto col = 0; col < 2; col++) {
						JJ[line][col] = JJmult[line][col];
					}
				}
			}

			for (auto line = 0; line < 2; line++) {
				for (auto col = 0; col < 2; col++) {
					JJnext[line][col] = JJ[line][col];
				}
			}
			
			t_complex detJ = JJ[0][0] * JJ[1][1] - JJ[0][1] * JJ[1][0];
			double det = norm(detJ);
			
			t_complex_xy photonOut = { valueXOut, valueYOut };
			

			outputSignals[0]->bufferPut(photonOut);
			alive = true;
		}
	}

	return alive;
}