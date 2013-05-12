My MScThesis Benchmarks
=======================

A small collection of benchmarks with the goal of answering some performance questions for my MSc Thesis.

## Zeros
__Goal:__ Allocate a matrix and fill it with zeros.

Compare which option is the fastest:

1. `malloc` followed by a call to `memset`
2. `calloc`
3. `arma::zeros`
4. `arma::mat` followed by a loop
5. `arma::mat` followed by a call to `mat.zeros`
