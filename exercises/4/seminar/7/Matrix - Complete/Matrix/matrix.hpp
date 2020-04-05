#include <iostream>
#include "rational.hpp"
#include "vector.hpp"
using namespace std;

#ifndef MATRIX
#define MATRIX

class Matrix {
    int N, M;
    Vector* data;

    void reallocData();
    void clearData();
    void copyData(const Matrix& m);

public:
    const int getRowCount() const;
    const int getColCount() const;

    Matrix getTransponsed() const;

    Matrix(Rational* data = nullptr, int N = 0, int M = 0);
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    ~Matrix();

    void reserve(int N, int M);

    Vector& operator[](int index);
    const Vector& operator[](int index) const;

    Matrix operator-() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(const Rational& other) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(const Rational& other);

    void print(ostream& out = cout) const;
    void read(istream& in = cin);
};

ostream& operator<<(ostream& out, const Matrix& m);
istream& operator>>(istream& in, Matrix& m);

#endif
