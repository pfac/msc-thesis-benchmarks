// c++ std headers
#include <iostream>
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
	Mat<double> matrix = zeros<Mat<double> >(n,n);
	sw.stop();

	cout << sw.ns() << endl;

	return 0;
}

