#include <iostream>
#include <cassert>
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

void Matrix::rightTriangle() {
    assert(N == M-1);

    for (int row1 = 0; row1 < N; ++row1) {
        for (int row2 = row1+1; row2 < N; ++row2) {
            Rational d = -(data[row2][row1] / data[row1][row1]);
            for (int col = row1; col < M; ++col) {
                data[row2][col] = data[row2][col] + (data[row1][col] * d);
            }
        }
    }
}

void Matrix::solve() {
    assert(N == M - 1);
    rightTriangle();

    Rational* solution = new Rational[N];
    for (int row = N - 1; row >= 0; --row) {
        Rational rightSide = data[row][M - 1];
        for (int col = row + 1; col < N; ++col) {
            rightSide = rightSide - (data[row][col] * solution[col]);
        }
        solution[row] = rightSide / data[row][row];
    }
    for (int i = 0; i < N; ++i) {
        solution[i].print();
        cout << " ";
    }
    cout << endl;
    delete[] solution;
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
