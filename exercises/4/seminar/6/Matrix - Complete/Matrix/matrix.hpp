#include <iostream>
#include "rational.hpp"
using namespace std;

#ifndef MATRIX
#define MATRIX

class Matrix {
    int N, M;
    Rational** data;

    void reallocData();
    void clearData();
    void copyData(const Matrix& m);

public:
    const int getRowCount() const;
    const int getColCount() const;

    Matrix(Rational* data = NULL, int N = 0, int M = 0);
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    ~Matrix();

    Rational*& operator[](int index);
    const Rational* operator[](int index) const;

    void print(ostream& out = cout) const;
    void read(istream& in = cin);
};

ostream& operator<<(ostream& out, const Matrix& m);
istream& operator>>(istream& in, Matrix& m);

#endif
