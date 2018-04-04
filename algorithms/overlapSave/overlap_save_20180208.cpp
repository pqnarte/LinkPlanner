# include "overlap_save_20180208.h"

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif


//########################################################################################################################################################
//############################################################### FFT Module #############################################################################
//########################################################################################################################################################

///////////
//// 1 ////
///////////
static size_t reverseBits(size_t x, unsigned int n)
{
	size_t result = 0;
	unsigned int i;
	for (i = 0; i < n; i++, x >>= 1)
		result = (result << 1) | (x & 1);
	return result;
}

///////////
//// 2 ////
///////////
vector<complex<double>> reImVect2ComplexVector(vector<double> &v1_real, vector<double> &v1_imag)
{
	vector<complex<double>> v_out(v1_real.size());

	for (size_t i = 0; i < v1_real.size(); ++i)
	{
		complex<double> iNum(v1_real[i], v1_imag[i]);
		v_out.at(i) = iNum;
	}

	return v_out;
}

///////////
//// 3 ////
///////////
vector<complex <double>> complexVectorMultiplication(vector<complex <double>> &v1_in, vector<complex <double>> &v2_in)
{
	vector<complex <double>> v_out(v1_in.size(), 0);
	for (unsigned int k = 0; k < v1_in.size(); ++k)
	{
		v_out.at(k) = v1_in.at(k)*v2_in.at(k);
	}
	return v_out;
}

///////////
//// 4 ////
///////////
vector<double> hilbertFilter(std::vector<std::complex<double>> &inTimeDomainComplex)
{
	auto n = inTimeDomainComplex.size();
	vector<double> filterReal;
	for (unsigned int i = 0; i < n; i++)
	{
		if (i == 0 || i == n / 2)
		{
			filterReal.push_back(1);
		}
		else if (i > 1 && i <= (n / 2) - 1)
		{
			filterReal.push_back(2);
		}
		else
		{
			filterReal.push_back(0);
		}
	}
	vector<double> filterImag(filterReal.size());
	vector<std::complex<double>> filter;
	filter = reImVect2ComplexVector(filterReal, filterImag);

	vector<std::complex<double>> inFrequencyDomainComplex;
	inFrequencyDomainComplex = fft(inTimeDomainComplex);

	vector<std::complex<double>> multiplicationFrequencyDomainComplex(n);

	for (unsigned int i = 0; i < n; i++)
	{
		multiplicationFrequencyDomainComplex[i] = inFrequencyDomainComplex[i] * filter[i];
	}

	vector<std::complex<double>> analyticalSignal(n);
	analyticalSignal = ifft(multiplicationFrequencyDomainComplex);

	vector<double> hilbertTransformed(n);

	for (unsigned int i = 0; i < n; i++)
	{
		hilbertTransformed[i] = analyticalSignal[i].imag();
	}

	return hilbertTransformed;
}

///////////
//// 5 ////
///////////
vector<complex<double>> fft(vector<complex<double> > &vec, int sign)
{
	vector<complex<double>> OUT(vec.size());
	vector<complex<double>> fftData(vec.size());
	vector<complex<double>> ifftData(vec.size());

	if (sign == -1)
	{
		fftData = fft(vec);
		OUT = fftData;
	}

	else

	{
		ifftData = ifft(vec);
		OUT = ifftData;
	}

	return OUT;
}

///////////
//// 6 ////
///////////
vector<complex<double>> fft(vector<complex<double> > &vec)
{
	size_t n = vec.size();

	if (n == 0)
		return vec;
	else if ((n & (n - 1)) == 0)  // Is power of 2
		transformRadix2(vec);
	else  // More complicated algorithm for arbitrary sizes
		transformBluestein(vec);

	double N = sqrt(static_cast<double>(n));
	for (size_t i = 0; i < n; i++)  // Scaling (because this FFT implementation omits it)
		vec[i] = vec[i] / N;


	return vec;
}

///////////
//// 7 ////
///////////
vector<complex<double>> ifft(vector<complex<double> > &vec)
{

	size_t n = vec.size();
	double N = sqrt(static_cast<double>(n));

	std::transform(vec.cbegin(), vec.cend(), vec.begin(), static_cast<complex<double>(*)(const complex<double> &)>(std::conj));

	fft(vec);
	for (size_t i = 0; i < n; i++)  // Scaling (because this FFT implementation omits it)
		vec[i] = vec[i] * N;

	std::transform(vec.cbegin(), vec.cend(), vec.begin(), static_cast<complex<double>(*)(const complex<double> &)>(std::conj));


	for (size_t i = 0; i < n; i++)  // Scaling (because this FFT implementation omits it)
		vec[i] = vec[i] / N;

	return vec;
}

///////////
//// 8 ////
///////////
void transformRadix2(vector<complex<double> > &vec)
{
	// Length variables
	size_t n = vec.size();
	int levels = 0;  // Compute levels = log2(n)
	for (size_t temp = n; temp > 1U; temp >>= 1)
		levels++;
	if (static_cast<size_t>(1U) << levels != n)
		throw "Length is not a power of 2";

	// Trignometric table
	vector<complex<double> > expTable(n / 2);
	for (size_t k = 0; k < n / 2; k++)
		expTable[k] = std::exp(complex<double>(0, -2 * M_PI * k / n));

	// Bit-reversed addressing permutation
	for (size_t i = 0; i < n; i++)
	{
		size_t j = reverseBits(i, levels);
		if (j > i)
			std::swap(vec[i], vec[j]);
	}

	// Cooley-Tukey decimation-in-time radix-2 FFT
	for (size_t size = 2; size <= n; size *= 2)
	{
		size_t halfsize = size / 2;
		size_t tablestep = n / size;

		for (size_t i = 0; i < n; i += size)	// Loop for intermediate stage
		{
			for (size_t j = i, k = 0; j < i + halfsize; j++, k += tablestep)
			{

				complex<double> temp = vec[j + halfsize] * expTable[k];
				vec[j + halfsize] = vec[j] - temp;
				vec[j] += temp;
			}
		}
		if (size == n)  // Prevent overflow in 'size *= 2'
			break;
	}
}

///////////
//// 9 ////
///////////
void transformBluestein(vector<complex<double> > &vec) {
	// Find a power-of-2 convolution length m such that m >= n * 2 + 1
	size_t n = vec.size();
	size_t m = 1;
	while (m / 2 <= n) {
		if (m > SIZE_MAX / 2)
			throw "Vector too large";
		m *= 2;
	}

	// Trignometric table
	vector<complex<double> > expTable(n);
	for (size_t k = 0; k < n; k++)
	{
		unsigned long long temp = static_cast<unsigned long long>(k) * k; // static_cast converts int "i" to unsigned long long "i". // temp = k^2
		temp %= static_cast<unsigned long long>(n) * 2;				// Modulo operation ==> temp = temp % static_cast<unsigned long long>(n) * 2 // temp = k^2 % 2n
		double angle = M_PI * temp / n;
		// Less accurate alternative if long long is unavailable: double angle = M_PI * i * i / n;
		expTable[k] = std::exp(complex<double>(0, -angle));
	}

	// Temporary vectors and preprocessing
	vector<complex<double> > av(m);
	for (size_t i = 0; i < n; i++)
		av[i] = vec[i] * expTable[i];
	vector<complex<double> > bv(m);
	bv[0] = expTable[0];
	for (size_t i = 1; i < n; i++)
		bv[i] = bv[m - i] = std::conj(expTable[i]);

	// Convolution
	vector<complex<double> > cv(m);
	convolve(av, bv, cv);					// Here size of cv equal to m

											// Postprocessing
	for (size_t i = 0; i < n; i++)
		vec[i] = cv[i] * expTable[i];
}

////////////
//// 10 ////
////////////
void convolve(const vector<complex<double> > &xvec, const vector<complex<double> > &yvec, vector<complex<double> > &outvec)
{

	size_t m = xvec.size();
	if (m != yvec.size() || m != outvec.size())
		throw "Mismatched lengths";
	vector<complex<double> > xv = xvec;
	vector<complex<double> > yv = yvec;
	double N = sqrt(static_cast<double>(m));

	fft(xv);
	for (size_t i = 0; i < m; i++)  // Scaling by sqrt(N)
		xv[i] = xv[i] * N;

	fft(yv);
	for (size_t i = 0; i < m; i++)  // Scalingby sqrt(N)
		yv[i] = yv[i] * N;

	for (size_t i = 0; i < m; i++)
		xv[i] *= yv[i];

	ifft(xv);
	for (size_t i = 0; i < m; i++)  // Scaling by sqrt(N)
		xv[i] = xv[i] * N;

	for (size_t i = 0; i < m; i++)  // Scaling (because this FFT implementation omits it)
		outvec[i] = xv[i] / static_cast<double>(m);
}

////////////
//// 11 ////
////////////
vector<complex<double>> fftshift(vector<complex<double>> &vec)
{
	unsigned long long N = vec.size();
	vector<complex<double>> output;

	if (N % 2 == 0)
	{
		for (unsigned long long i = N / 2; i < vec.size(); i++)
		{
			output.push_back(vec[i]);
		}

		for (unsigned long long i = 0; i < N / 2; i++)
		{
			output.push_back(vec[i]);
		}
	}
	else
	{
		N = N + 1;
		for (unsigned long long i = N / 2; i < vec.size(); i++)
		{
			output.push_back(vec[i]);
		}

		for (unsigned long long i = 0; i < N / 2; i++)
		{
			output.push_back(vec[i]);
		}

	}

	return output;

}

////////////
//// 12 ////
////////////
vector<std::complex<double>> ifftshift(std::vector<std::complex<double>> &vec)
{
	unsigned long long N = vec.size();
	vector<std::complex<double>> output;

	if (N % 2 == 0)
	{
		for (unsigned long long i = N / 2; i < vec.size(); i++)
		{
			output.push_back(vec[i]);
		}

		for (unsigned long long i = 0; i < N / 2; i++)
		{
			output.push_back(vec[i]);
		}
	}
	else
	{
		N = N + 1;
		for (unsigned long long i = (N / 2) - 1; i < vec.size(); i++)
		{
			output.push_back(vec[i]);
		}

		for (unsigned long long i = 0; i < (N / 2) - 1; i++)
		{
			output.push_back(vec[i]);
		}

	}


	return output;
}

////////////
//// 13 ////
////////////
std::vector<std::complex<double>> overlapSave(std::vector<std::complex<double> > &inTimeDomainComplex, std::vector<std::complex<double> > &inTimeDomainFilterComplex)
{
	size_t impulseResponseLength = inTimeDomainFilterComplex.size();  // Initial size of filter
	size_t N;									  // FFT size

	if ((impulseResponseLength & (impulseResponseLength - 1)) == 0)						  // Is power of 2
	{
		N = impulseResponseLength * 2;
	}
	else
	{
		size_t m = 1;
		while (m <= impulseResponseLength)					// This calculates next value of power of 2
		{
			m *= 2;
		}

		N = m;
	}

	// Now, check if the value of (N-impulseResponseLength) is less than or equal to the 25% of N,
	// then double the size of the N.

	size_t L = N - impulseResponseLength + 1;			// Size of data block (Here, we used fix 50% overlap)
	size_t overlap = N - L;		// size of overlap

	size_t Dl = inTimeDomainComplex.size();
	int extraZero = 0;
	if (Dl % L == 0)
	{
		inTimeDomainComplex = inTimeDomainComplex;
	}
	else
	{
		// This changes the length of data if it's not interger multiple of L
		size_t Dlnew = inTimeDomainComplex.size();
		while (Dlnew % L != 0)
		{
			inTimeDomainComplex.push_back((0, 0));
			Dlnew = inTimeDomainComplex.size();
			extraZero += 1;
		}
	}



	vector <complex<double>>  filterTD(N); // Time domain filter
	vector <complex<double>>  filterFD(N); // Freq domain filter

	for (unsigned int i = 0; i < inTimeDomainFilterComplex.size(); i++)
	{
		filterTD[i] = inTimeDomainFilterComplex[i];
		filterTD[i] = filterTD[i] * (sqrt(filterTD.size())); //Scaling ny sqrt(N)
	}
	filterFD = fft(filterTD);



	//////////////////////////////// Section 4 /////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////// Create Matrix ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////


	size_t nr = inTimeDomainComplex.size() / L;

	vector < vector<complex<double>> > matrix;
	vector <complex<double>> tempVector(L); // Without overlap
	vector <complex<double>> tempVectorA(N); // With overlap


	size_t position = 0;

	for (unsigned int i = 0; i < nr; i++)
	{

		for (unsigned int j = 0; j < L; j++)
		{
			tempVector[j] = inTimeDomainComplex[position + j]; // Take data withot overlap
		}


		if (i == 0)
		{
			for (unsigned int k = 0; k < tempVector.size(); k++)
			{
				tempVectorA[overlap + k] = tempVector[k];  // For first block, overlap is zero
			}
		}
		else
		{
			vector <complex<double>> tempVectorM = matrix[i - 1];
			for (unsigned int m = 0; m < overlap; m++)
			{
				tempVectorA[m] = tempVectorM[L + m];
			}
			for (unsigned int n = 0; n < L; n++)
			{
				tempVectorA[overlap + n] = tempVector[n];
			}
		}


		matrix.push_back(tempVectorA);
		position = position + L;
	}


	//////////////////////////////// Section 4 /////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////// Convolution ////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

	for (unsigned int p = 0; p < matrix.size(); p++)
	{
		vector <complex<double>> dataBlock = matrix[p];
		vector <complex<double>> dataBlockTD = dataBlock;

		dataBlockTD = fft(dataBlockTD);	 // Here to very with MATLAB, multiply this data with SQRT(N)

		for (unsigned int q = 0; q < dataBlockTD.size(); q++)
		{
			dataBlockTD[q] = dataBlockTD[q] * filterFD[q]; // Multiplication with filter data
		}

		dataBlockTD = ifft(dataBlockTD);				  // ifft to get filtered data

		matrix[p] = dataBlockTD;						  // save data to matrix
	}

	// Next, create vector from a matrix by disarding the overlap 
	vector <complex<double>> y_aux(inTimeDomainComplex.size());
	size_t startPosition = 0;

	for (unsigned int r = 0; r < matrix.size(); r++)
	{

		vector <complex<double>> tempVectorB = matrix[r];

		for (unsigned int s = 0; s < L; s++)
		{
			y_aux[startPosition + s] = tempVectorB[overlap + s];
		}

		startPosition = startPosition + L;
	}

	// Next, discard last "extrazero" samples. 
	vector <complex<double>> y(inTimeDomainComplex.size() - extraZero);

	for (unsigned int t = 0; t < y_aux.size() - extraZero; t++)
	{
		y[t] = y_aux[t];
	}

	//////////////////////////////// Section 6 ///////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	/////////////////////////////// Display Section //////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	/*
	// Display length of data
	cout << "\nTotal length of of data,     Dl = " << count << endl;
	cout << "\nTotal length of of Filter,	M = " << countFilter << endl;
	cout << "\nTotal length of of Filter after zero padding = " << filterFD.size() << endl;
	cout << "\nTotal length of of data after zero padding,    Dlnew = " << inTimeDomainComplex.size() << " (This is because to make the data length of itnger multiple of L)" << endl;

	cout << endl << endl;

	cout << "length of data block size,  L = " << L << endl;
	cout << "length of FFT size,         N = " << N << endl;
	cout << "Length of overlap,    overlap = " << overlap << endl;*/

	return y;

}

////////////
//// 14 ////
////////////
std::vector<std::complex<double>> overlapSave(std::vector<std::complex<double> > &inTimeDomainComplex1, std::vector<std::complex<double> > &inTimeDomainComplex2, std::vector<std::complex<double> > &inTimeDomainFilterComplex)
{
	vector<complex<double>> currentCopy = inTimeDomainComplex1;
	vector<complex<double>> previousCopy = inTimeDomainComplex2;
	vector<complex<double>> dataBlock = inTimeDomainComplex2;
	vector<complex<double>> filter = inTimeDomainFilterComplex;
	size_t overlap = previousCopy.size();

	for (unsigned int i = 0; i < currentCopy.size(); i++)
	{
		dataBlock.push_back(currentCopy[i]);
	}

	size_t N = dataBlock.size();

	if ((N & (N - 1)) == 0)
	{
		N = N;
	}
	else
	{
		size_t m = 1;
		while (m <= N)					// This calculates next value of power of 2
		{
			m *= 2;
		}

		N = m;
	}

	vector<complex<double>> dataBlockModified(N);
	for (unsigned int i = 0; i < dataBlock.size(); i++)
	{
		dataBlockModified[i] = dataBlock[i];
	}


	vector<complex<double>> y(N);

	y = overlapSave(dataBlock, filter);

	return y;
}

////////////
//// 15 ////
////////////

std::vector<std::complex<double>> overlapSaveWithTransferFunction(std::vector<std::complex<double> > &inTimeDomainComplex1, std::vector<std::complex<double> > &inTimeDomainComplex2, std::vector<std::complex<double> > &inFilterTransferFunctionComplex)
{
	vector<complex<double>> currentCopy = inTimeDomainComplex1;
	vector<complex<double>> previousCopy = inTimeDomainComplex2;
	vector<complex<double>> filter = inFilterTransferFunctionComplex;

	size_t N = filter.size();
	size_t L = N / 2;
	size_t overlapSize = N / 2;

	vector<complex<double>> overlap;
	for(size_t i= previousCopy.size()-overlapSize; i<previousCopy.size(); i++)
	{ overlap.push_back(previousCopy[i]); }

	vector<complex<double>> dataBlock; // previousCopy1, previousCopy2 and currentCopy concotanation
	dataBlock.reserve(overlap.size() + currentCopy.size());
	dataBlock.insert(dataBlock.end(), overlap.begin(), overlap.end());
	dataBlock.insert(dataBlock.end(), currentCopy.begin(), currentCopy.end());

	// Make dataBlock to be integer multiple of N

	size_t Dl = dataBlock.size();
	unsigned int extraZero = 0;
	if (Dl % L == 0)
	{
		dataBlock = dataBlock;
	}
	else
	{
		// This changes the length of data if it's not interger multiple of L
		size_t Dlnew = dataBlock.size();
		while (Dlnew % L != 0)
		{
			dataBlock.push_back((0, 0));
			Dlnew = dataBlock.size();
			extraZero += 1;
		}
	}


	//////////////////////////////// Section 4 /////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////// Create Matrix ///////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	size_t nr = dataBlock.size() / L;

	vector < vector<complex<double>> > matrix;
	vector <complex<double>> tempVector(N); // With overlap
	size_t position = 0;

	for (unsigned int i = 0; i < nr-1; i++)
	{

		for (unsigned int j = 0; j < N; j++)
		{
			tempVector[j] = dataBlock[position + j]; // Take data withot overlap
		}

		/*{
			vector <complex<double>> tempVectorM = matrix[i - 1];
			for (unsigned int m = 0; m < overlapSize; m++)
			{
				tempVectorA[m] = tempVectorM[L + m];
			}
			for (unsigned int n = 0; n < L; n++)
			{
				tempVectorA[overlapSize + n] = tempVector[n];
			}
		}*/

		matrix.push_back(tempVector);
		position = position + L;
	}


	//////////////////////////////// Section 4 /////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////// Convolution ////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

	for (unsigned int p = 0; p < matrix.size(); p++)
	{
		vector <complex<double>> dataBlockSegment = matrix[p];
		vector <complex<double>> dataBlockTD = dataBlockSegment;

		dataBlockTD = fft(dataBlockTD);	 // Here to very with MATLAB, multiply this data with SQRT(N)

		for (unsigned int q = 0; q < dataBlockTD.size(); q++)
		{
			dataBlockTD[q] = dataBlockTD[q] * filter[q]; // Multiplication with filter data
		}

		dataBlockTD = ifft(dataBlockTD);				  // ifft to get filtered data

		matrix[p] = dataBlockTD;						  // save data to matrix
	}

	// Next, create vector from a matrix by disarding the overlap 
	vector <complex<double>> y_aux(dataBlock.size()-overlapSize);
	size_t startPosition = 0;

	for (unsigned int r = 0; r < matrix.size(); r++)
	{

		vector <complex<double>> tempVectorB = matrix[r];

		for (unsigned int s = 0; s < L; s++)
		{
			y_aux[startPosition + s] = tempVectorB[overlapSize + s];
		}

		startPosition = startPosition + L;
	}

	// Next, discard last "extrazero" samples. 
	vector <complex<double>> y(y_aux.size() -  extraZero);

	for (unsigned int t = 0; t < y_aux.size() - extraZero; t++)
	{
		y[t] = y_aux[t];
	}

	return y;
}

std::vector<std::complex<double>> overlapSaveTFN(std::vector<std::complex<double> > &inTimeDomainComplex, std::vector<std::complex<double> > &inTransferFunctionComplex)
{
	vector<complex<double>>dataBlockFrequencyDomain; // FFT of dataBlock
	dataBlockFrequencyDomain = fft(inTimeDomainComplex);

	vector<complex<double>> y;
	y = complexVectorMultiplication(dataBlockFrequencyDomain, inTransferFunctionComplex); // Vector multiplication
	y = ifft(y);

	return y;



}

////////////
//// 16 ////
////////////
std::vector<std::complex<double>> conv(std::vector<std::complex<double>> &inTimeDomainComplex1, std::vector<std::complex<double>> &inTimeDomainComplex2)
{
	// Here we will calculate the length of the linear convolution L = M+N-1
	size_t M = inTimeDomainComplex1.size();
	size_t N = inTimeDomainComplex2.size();

	size_t L = M + N - 1;

	vector<std::complex<double>> xn(L);
	vector<std::complex<double>> hn(L);

	// Change length of both vectr by zero padding
	for (unsigned int i = 0; i < L; i++)
	{
		xn[i] = inTimeDomainComplex1[i];
		hn[i] = inTimeDomainComplex2[i];
	}

	// Calculate linear convolution using Circular convolution conversion
	vector<std::complex<double>> XN(L);
	vector<std::complex<double>> HN(L);
	vector<std::complex<double>> y(L);

	XN = fft(xn);
	HN = fft(hn);
	y = complexVectorMultiplication(XN, HN);
	y = ifft(y);

	return y;
}

////////////
//// 17 ////
////////////
std::vector<std::complex<double>> circularConv(std::vector<std::complex<double>> &inTimeDomainComplex1, std::vector<std::complex<double>> &inTimeDomainComplex2) 

{
	// Here we will calculate the length of the linear convolution L = min(impulseResponseLength,N)
	size_t M = inTimeDomainComplex1.size();
	size_t N = inTimeDomainComplex2.size();

	size_t L = min(M, N);

	vector<std::complex<double>> xn(L);
	vector<std::complex<double>> hn(L);

	// Change length of both vectr by zero padding
	for (unsigned int i = 0; i < L; i++)
	{
		xn[i] = inTimeDomainComplex1[i];
		hn[i] = inTimeDomainComplex2[i];
	}

	// Calculate linear convolution using Circular convolution conversion
	vector<std::complex<double>> XN(L);
	vector<std::complex<double>> HN(L);
	vector<std::complex<double>> y(L);

	XN = fft(xn);
	HN = fft(hn);
	y = complexVectorMultiplication(XN, HN);
	y = ifft(y);

	return y;

}

////////////
//// 18 ////
////////////
std::vector<std::complex<double>> transferFunctionToImpulseResponse(std::vector<std::complex<double>> &transferFunction)
{
	// Calculate the impulse response of the filter
	vector<complex<double>> transferFunctionComplex = transferFunction;
	vector<complex<double>> impulseResponseComplex(transferFunctionComplex.size());
	vector<complex<double>> impulseResponse(transferFunctionComplex.size());

	transferFunctionComplex = ifftshift(transferFunctionComplex); // ifftshift 
	impulseResponseComplex = ifft(transferFunctionComplex);		  // ifft	   
	impulseResponseComplex = fftshift(impulseResponseComplex);	  // fftshift 

	for (unsigned int i = 0; i < impulseResponseComplex.size(); i++) {
		impulseResponseComplex[i] = impulseResponseComplex[i] / (sqrt((impulseResponseComplex.size())));
	}

	vector<double> realImpulseResponse(impulseResponseComplex.size());
	for (int i = 0; i < impulseResponseComplex.size(); i++) { realImpulseResponse[i] = (impulseResponseComplex[i].real()); }
	double maxValue = *std::max_element(realImpulseResponse.begin(), realImpulseResponse.end());

	for (unsigned int i = 0; i < transferFunctionComplex.size(); i++) {
		impulseResponse[i] = static_cast<complex<double>>((1 / maxValue)*realImpulseResponse[i]);
	}

	return impulseResponse;
}

std::vector<std::complex<double>> transferFunctionToImpulseResponseNEW(std::vector<std::complex<double>> &transferFunction)
{
	// Calculate the impulse response of the filter
	vector<complex<double>> transferFunctionComplex = transferFunction;
	vector<complex<double>> impulseResponseComplex(transferFunctionComplex.size());
	vector<complex<double>> impulseResponse(transferFunctionComplex.size());

	transferFunctionComplex = ifftshift(transferFunctionComplex); // ifftshift
	impulseResponseComplex = ifft(transferFunctionComplex);		  // ifft	   
	impulseResponseComplex = fftshift(impulseResponseComplex);	  // fftshift

	for (unsigned int i = 0; i < impulseResponseComplex.size(); i++) {
		impulseResponseComplex[i] = impulseResponseComplex[i] / (sqrt((impulseResponseComplex.size())));
	}

	for (unsigned int i = 0; i < transferFunctionComplex.size(); i++) {
		impulseResponse[i] = static_cast<complex<double>>(impulseResponseComplex[i].real());
	}

	return impulseResponse;
}
