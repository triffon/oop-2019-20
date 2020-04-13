#include <iostream>
#include <cassert>
#include "vector.hpp"
#include "matrix.hpp"
using namespace std;

// ------------------ private methods ---------------------------

void Matrix::reallocData() {
    clearData();
    this->data = new Vector [N];
    for (int i = 0; i < N; ++i) {
        data[i].reserve(M);
    }
}

void Matrix::clearData() {
    if (data == NULL) {
        return;
    }

    delete [] data;
}

void Matrix::copyData(const Matrix& m) {
    N = m.N;
    M = m.M;
    reallocData();

    for(int i = 0; i< m.N; ++i) {
        data[i] = m.data[i];
    }
}

// ------------------ getters ---------------------------

const int Matrix::getRowCount() const {
    return N;
}

const int Matrix::getColCount() const {
    return M;
}

Matrix Matrix::getTransponsed() const {
    Matrix result;
    result.reserve(M, N);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = data[j][i];
        }
    }
    return result;
}

// ------------------ big four ---------------------------

Matrix::Matrix(Rational* data, int N, int M): data(NULL), N(N), M(M) {
    if(data == NULL) {
        return;
    }
    reallocData();

    for(int i = 0; i< N; ++i) {
        this->data[i] = Vector(&(data[i*M]), M);
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
    clearData();
}

// ------------------ public -------------------------------

void Matrix::reserve(int N, int M) {
    clearData();
    this->N = N;
    this->M = M;
    data = new Vector[N];
    for (int i = 0; i < N; ++i) {
        data[i].reserve(M);
    }
}

// ------------------ operators ---------------------------

Vector& Matrix::operator[](int index) {
    return data[index];
}

const Vector& Matrix::operator[](int index) const {
    return data[index];
}

// ------------------- arithmetic -------------------------

Matrix Matrix::operator-() const {
    Matrix result(*this);
    
    for (int i = 0; i < N; ++i) {
        result.data[i] = -data[i];
    }

    return result;
}


Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(*this);

    for (int i = 0; i < N; ++i) {
        result.data[i] += other.data[i];
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    return (*this) + (-other);
}

Matrix Matrix::operator*(const Matrix& other) const {
    assert(N == other.M && M == other.N);

    Matrix result;
    result.reserve(N, other.M);
    Matrix otherTransposed = other.getTransponsed();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < other.M; ++j) {
            result[i][j] = data[i].dot(otherTransposed[j]);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Rational& other) const {
    Matrix result(*this);

    for (int i = 0; i < N; ++i) {
        result.data[i] *= other;
    }

    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    (*this) = (*this) + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    (*this) = (*this) - other;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    (*this) = (*this) * other;
    return *this;
}

Matrix& Matrix::operator*=(const Rational& other) {
    (*this) = (*this) * other;
    return *this;
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
            in>> data[i][j];
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