# ifndef POLARIZATION_BEAM_SPLITTER_H_
# define POLARIZATION_BEAM_SPLITTER_H_

<<<<<<< HEAD
=======
#include "netxpto_20180118.h"

#include <array>
>>>>>>> Develop.Mariana_TQ

class PolarizationBeamSplitter : public Block {

	/* input parameters */

<<<<<<< HEAD
=======
	t_real F = 1;
	t_complex unit = 1;
	array <t_complex, 4> matrixH = { { F*unit, 0, 0, 0 } };
	array <t_complex, 4> matrixV = { { 0, 0, 0, F*unit } };
	/*
	Jones Matrix for PBS:
	1	0
	0	1
	*/

>>>>>>> Develop.Mariana_TQ
public:

	PolarizationBeamSplitter(vector<Signal *> &inputSignals, vector<Signal *> &outputSignals) : Block(inputSignals, outputSignals) {};

	void initialize(void);

	bool runBlock(void);

<<<<<<< HEAD
=======
	void setTransferMatrixH(array<complex<double>, 4> TransferMatrix) { matrixH = TransferMatrix; }
	array<complex<double>, 4> const getTransferMatrixH(void) { return matrixH; }

	void setTransferMatrixV(array<complex<double>, 4> TransferMatrix) { matrixV = TransferMatrix; }
	array<complex<double>, 4> const getTransferMatrixV(void) { return matrixV; }

>>>>>>> Develop.Mariana_TQ
};

#endif