// c++ std headers
#include <iostream>
	using std::cout;

// c std headers
#include <stdlib.h>
#include <string.h>

// other headers
#include <cuk/stopwatch>
	using cuk::stopwatch;

#define endl '\n'



int main () {
	const unsigned n = DIMENSION;
	const size_t bytes = n * n * sizeof(double);

	stopwatch sw;
	sw.start();
	double * matrix = (double*) malloc(bytes);
	memset(matrix, 0, bytes);
	sw.stop();

	free(matrix);

	cout << sw.ns() << endl;

	return 0;
}

