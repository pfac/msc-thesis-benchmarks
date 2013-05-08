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



template<typename T>
double benchmark_malloc_memset (const unsigned n) {
	const unsigned bytes = n * n * sizeof(T);

	stopwatch sw;
	sw.start();
	T * matrix = (T*) malloc(bytes);
	memset(matrix, 0, bytes);
	sw.stop();

	return sw.ns();
}



template<typename T>
double benchmark_calloc (const unsigned n) {
	const unsigned nn = n * n;

	stopwatch sw;
	sw.start();
	T * matrix = (T*) calloc(nn, sizeof(T));
	sw.stop();

	return sw.ns();
}



template<typename T>
double benchmark_arma_zeros (const unsigned n) {
	stopwatch sw;
	sw.start();
	Mat<T> matrix = zeros<Mat<T> >(n,n);
	sw.stop();

	return sw.ns();
}



template<typename T>
double benchmark_arma_mat_for (const unsigned n) {
	stopwatch sw;
	sw.start();
	Mat<T> matrix(n,n);
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < n; ++j)
			matrix(i,j) = T(0);
	sw.stop();

	return sw.ns();
}



int main (int, char * argv[]) {
	clog <<
"Benchmark " << argv[0] << 
"  compares the various methods for alocating a square matrix and filling it with "
"zeros: malloc+memset, calloc, arma::zeros, arma::mat+loop\033[32" << endl << endl;

	const unsigned n = 16000;

	clog << ":: malloc + memset ::" << endl;
	cout << benchmark_malloc_memset<double>(n) << endl;
	
	clog << ":: calloc ::" << endl;
	cout << benchmark_calloc<double>(n) << endl;

	clog << ":: arma::zeros ::" << endl;
	cout << benchmark_arma_zeros<double>(n) << endl;

	clog << ":: arma::mat + loop ::" << endl;
	cout << benchmark_arma_mat_for<double>(n) << endl;

	return 0;
}