// c++ std headers
#include <iostream>
	using std::cout;

// other headers
#include <cuk/stopwatch>
	using cuk::stopwatch;

#define endl '\n'


int main () {
	const unsigned n = DIMENSION;
	const unsigned nn = n * n;

	stopwatch sw;
	sw.start();
	double * matrix = (double*) calloc(nn, sizeof(double));
	sw.stop();

	free(matrix);

	cout << sw.ns() << endl;

	return 0;
}