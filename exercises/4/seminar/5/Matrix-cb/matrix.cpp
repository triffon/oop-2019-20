#include <iostream>
#include "matrix.hpp"
using namespace std;

void Matrix::clearData() {
    for(int i = 0; i< N; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

void Matrix::copyData(const Matrix& m) {
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

void Matrix::print() {
    for(int i = 0; i< N; ++i) {
        for(int j = 0; j< M; ++j) {
            data[i][j].print();
            cout<< " ";
        }
        cout<< endl;
    }
}
