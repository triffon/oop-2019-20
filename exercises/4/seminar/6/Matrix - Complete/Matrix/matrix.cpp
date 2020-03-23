#include <iostream>
#include <cassert>
#include "matrix.hpp"
using namespace std;

// ------------------ private methods ---------------------------

void Matrix::reallocData() {
    clearData();

    this->data = new Rational * [N];
    for (int i = 0; i < N; ++i) {
        this->data[i] = new Rational[M];
    }
}

void Matrix::clearData() {
    if (data == NULL) {
        return;
    }

    for(int i = 0; i< N; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

void Matrix::copyData(const Matrix& m) {
    N = m.N;
    M = m.M;
    reallocData();

    for(int i = 0; i< m.N; ++i) {
        for(int j = 0; j< m.M; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

// ------------------ getters ---------------------------

const int Matrix::getRowCount() const {
    return N;
}

const int Matrix::getColCount() const {
    return M;
}

// ------------------ big four ---------------------------

Matrix::Matrix(Rational* data, int N, int M): data(NULL), N(N), M(M) {
    if(data == NULL) {
        return;
    }
    reallocData();

    for(int i = 0; i< N; ++i) {
        for(int j = 0; j< M; ++j) {
            this->data[i][j] = data[i*M + j];
        }
    }
}

Matrix::Matrix(const Matrix& m): data(NULL), N(m.N), M(m.M) {
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
    for(int i = 0; i< N; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

// ------------------ operators ---------------------------

Rational*& Matrix::operator[](int index) {
    return data[index];
}

const Rational* Matrix::operator[](int index) const {
    return data[index];
}

// ------------------ read/write ---------------------------

void Matrix::print(ostream& out) const {
    for(int i = 0; i< N; ++i) {
        for(int j = 0; j< M; ++j) {
            out<< data[i][j] << " ";
        }
        out<< endl;
    }
}

void Matrix::read(istream& in) {
    in >> N >> M;
    reallocData();
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>> data[i][j];
        }
    }
}

ostream& operator<<(ostream& out, const Matrix& m) {
    m.print(out);
    return out;
}

istream& operator>>(istream& in, Matrix& m) {
    m.read(in);
    return in;
}