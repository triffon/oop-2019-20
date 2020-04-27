#include <iostream>
#include <cassert>
#include "matrix.hpp"
using namespace std;

// ------------------------ private method -------------------

void Matrix::clearData() {
    delete [] data;
}

void Matrix::copyData(const Matrix& m) {
    N = m.N;
    M = m.M;

    data = new Vector[N];
    for(int i = 0; i< m.N; ++i) {
        data[i] = m.data[i];
    }
}

// ------------------------ big four -------------------

Matrix::Matrix(Rational* data, int N, int M): data(NULL), N(N), M(M) {
    if(data == NULL) {
        return;
    }

    this->data = new Vector[N];
    for(int i = 0; i< N; ++i) {
        this->data[i] = Vector(&(data[i*M]), M);
    }
}

Matrix::Matrix(const Matrix& m) {
    copyData(m);
}

Matrix& Matrix::operator=(const Matrix& m) {
    if(this == &m) {
        return *this;
    }
    clearData();
    copyData(m);
    return *this;
}

Matrix::~Matrix() {
    delete [] data;
}

// ---------------------- methods ------------------------

void Matrix::reserve(int N, int M) {
    clearData();
    this->N = N;
    this->M = M;

    data = new Vector[N];
    for (int i = 0; i < N; ++i) {
        data[i].reserve(M);
    }
}

// ------------------- getters/setters -------------------

int Matrix::getRowsCount() const {
    return N;
}

int Matrix::getColsCount() const {
    return M;
}

// ------------------- operators ---------------------------

Vector& Matrix::operator[](int index) {
    return data[index];
}

// ------------------------ input/output -------------------

void Matrix::read(istream& in) {
    in >> N >> M;
    clearData();

    data = new Vector[N];
    for (int i = 0; i < N; ++i) {
        data[i].reserve(M);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            in>> data[i][j];
        }
    }
}

void Matrix::print(ostream& out) const {
    for(int i = 0; i< N; ++i) {
        for(int j = 0; j< M; ++j) {
            out<< data[i][j] << " ";
        }
        out<< endl;
    }
}

istream& operator>>(istream& in, Matrix& m){
    m.read(in);
    return in;
}

ostream& operator<<(ostream& out, const Matrix& m) {
    m.print(out);
    return out;
}
