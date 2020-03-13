#include <iostream>
#include "ration.hpp"
#ifndef MATRIX
#define MATRIX

class Matrix {
    int N, M;
    Rational** data;

    void clearData();
    void copyData(const Matrix& m);

public:
    Matrix(Rational** data = NULL, int N = 0, int M = 0);
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    ~Matrix();
};

#endif
