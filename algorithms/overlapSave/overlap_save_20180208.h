#pragma once
# ifndef PROGRAM_INCLUDE_OVERLAP_AND_SAVE_H_
# define PROGRAM_INCLUDE_OVERLAP_AND_SAVE_H_

# include <vector>
# include <complex>
#include <algorithm>

using namespace std;

//########################################################################################################################################################
//############################################################### FFT MODULE #############################################################################
//########################################################################################################################################################

vector<complex<double>> reImVect2ComplexVector(vector<double> &v1_real, vector<double> &v1_imag);
vector<complex <double>> complexVectorMultiplication(vector<complex <double>> &v1_in, vector<complex <double>> &v2_in);


std::vector<std::complex<double>> fft(std::vector<std::complex<double>> &vec, int sign);
std::vector<std::complex<double>> fft(std::vector<std::complex<double> > &vec);
std::vector<std::complex<double>> ifft(std::vector<std::complex<double> > &vec);
void transformRadix2(std::vector<std::complex<double> > &vec);
void transformBluestein(std::vector<std::complex<double> > &vec);
void convolve(const std::vector<std::complex<double> > &vecx, const std::vector<std::complex<double> > &vecy, std::vector<std::complex<double> > &vecout);

std::vector<std::complex<double>> fftshift(std::vector<std::complex<double>> &vec);  // fftshift
std::vector<std::complex<double>> ifftshift(std::vector<std::complex<double>> &vec); // ifftshift

std::vector<std::complex<double>> overlapSave(std::vector<std::complex<double> > &inTimeDomainComplex, std::vector<std::complex<double> > &inTimeDomainFilterComplex);
std::vector<std::complex<double>> overlapSave(std::vector<std::complex<double> > &inTimeDomainComplex1, std::vector<std::complex<double> > &inTimeDomainComplex2, std::vector<std::complex<double> > &inTimeDomainFilterComplex);
std::vector<std::complex<double>> overlapSaveWithTransferFunction(std::vector<std::complex<double> > &inTimeDomainComplex1, std::vector<std::complex<double> > &inTimeDomainComplex2, std::vector<std::complex<double> > &inTimeDomainFilterComplex);

std::vector<std::complex<double>> overlapSaveTFN(std::vector<std::complex<double> > &inTimeDomainComplex, std::vector<std::complex<double> > &inTransferFunctionComplex);


std::vector<std::complex<double>> conv(std::vector<std::complex<double>> &inTimeDomainComplex1, std::vector<std::complex<double>> &inTimeDomainComplex2); // Convolution
std::vector<std::complex<double>> circularConv(std::vector<std::complex<double>> &inTimeDomainComplex1, std::vector<std::complex<double>> &inTimeDomainComplex2); // Circular convolution


std::vector<std::complex<double>> transferFunctionToImpulseResponse(std::vector<std::complex<double>> &transferFunction);    // transfer function to impulse response
std::vector<std::complex<double>> transferFunctionToImpulseResponseNEW(std::vector<std::complex<double>> &transferFunction); // transfer function to impulse response for FD_Filter 


//########################################################################################################################################################
//######################################################### FILTER TRANSFER FUNCTIONS ####################################################################
//########################################################################################################################################################

std::vector<std::complex<double>> hilbert(std::vector<std::complex<double>> &inTimeDomainComplex);

# endif
