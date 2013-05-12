// c++ std headers
#include <iostream>
	using std::clog;
	using std::cout;

// other headers
#include <cuk/stopwatch>
	using cuk::stopwatch;

#include <armadillo>
	using arma::Mat;
	using arma::zeros;

#define endl '\n'



int main () {
	const unsigned n = DIMENSION;

	stopwatch sw;
	sw.start();
	Mat<double> matrix(n,n);
	#pragma omp parallel for
	for (unsigned i = 0; i < n; ++i)
	{
		#pragma omp parallel for
		for (unsigned j = 0; j < i; ++j)
			matrix(i,j) = 0;
	}
	sw.stop();

	cout << sw.ns() << endl;

	return 0;
}