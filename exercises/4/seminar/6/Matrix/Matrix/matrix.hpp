#include <iostream>
#include "rational.hpp"
using namespace std;
#ifndef MATRIX
#define MATRIX

class Matrix {
    int N, M;
    Rational** data;

    void clearData();
    void copyData(const Matrix& m);

public:
    Matrix(Rational* data = NULL, int N = 0, int M = 0);
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    ~Matrix();

    int getRowsCount() const;
    int getColsCount() const;

    Rational*& operator[](int index);

    void read(istream& in = cin);
    void print(ostream& out = cout) const;
};

istream& operator>>(istream& in, Matrix& m);
ostream& operator<<(ostream& out, const Matrix& m);

#endif
