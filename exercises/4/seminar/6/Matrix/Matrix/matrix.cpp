#include <iostream>
#include <cassert>
#include "matrix.hpp"
using namespace std;

// ------------------------ private method -------------------

void Matrix::clearData() {
    for(int i = 0; i< N; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

void Matrix::copyData(const Matrix& m) {
    N = m.N;
    M = m.M;

    data = new Rational*[N];
    for(int i = 0; i< m.N; ++i) {
        data[i] = new Rational[m.M];
    }

    for(int i = 0; i< m.N; ++i) {
        for(int j = 0; j< m.M; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

// ------------------------ big four -------------------

Matrix::Matrix(Rational* data, int N, int M): data(NULL), N(N), M(M) {
    if(data == NULL) {
        return;
    }

    this->data = new Rational*[N];
    for(int i = 0; i< N; ++i) {
        this->data[i] = new Rational[M];
    }

    for(int i = 0; i< N; ++i) {
        for(int j = 0; j< M; ++j) {
            this->data[i][j] = data[i*M + j];
        }
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
    for(int i = 0; i< N; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

// ------------------- getters/setters -------------------

int Matrix::getRowsCount() const {
    return N;
}

int Matrix::getColsCount() const {
    return M;
}

// ------------------- operators ---------------------------

Rational*& Matrix::operator[](int index) {
    return data[index];
}

// ------------------------ input/output -------------------

void Matrix::read(istream& in) {
    in >> N >> M;
    clearData();

    data = new Rational*[N];
    for (int i = 0; i < N; ++i) {
        data[i] = new Rational[M];
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
