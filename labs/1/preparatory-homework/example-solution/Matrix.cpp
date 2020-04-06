#include "Matrix.h"
#include <cstring>
#include <cmath>
#include <cstdlib>

Matrix::Matrix(size_t rows, size_t cols, const char* name)
    : m_name(new char[strlen(name) + 1])
    , m_rows(rows)
    , m_cols(cols)
{
    m_mat = initMat(m_rows, m_cols);
    strcpy(m_name, name);
}


Matrix::Matrix(const Matrix& other)
{
    copy(other);
}


Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Matrix::~Matrix()
{
    clear();
}


std::istream& operator>>(std::istream& in, Matrix& obj)
{
    for (size_t i = 0; i < obj.m_rows; i++)
        for (size_t j = 0; j < obj.m_cols; j++)
            in >> obj[i][j];
    return in;
}


std::ostream& operator<<(std::ostream& out, const Matrix& obj)
{
    for (size_t i = 0; i < obj.m_rows; i++) {
        for (size_t j = 0; j < obj.m_cols; j++)
            out << obj[i][j] << " ";
        out << std::endl;
    }
    return out;
}


Matrix& Matrix::operator+=(const Matrix& other)
{
    if (m_rows == other.m_rows && m_cols == other.m_cols) {
        for (size_t i = 0; i < m_rows; i++)
            for (size_t j = 0; j < m_cols; j++)
                m_mat[i][j] += other.m_mat[i][j];

        char* newName = constructName(other, '+');
        delete[] m_name;
        m_name = newName;
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    if (m_cols == other.m_rows) {
        Matrix::elem_t** newMat = initMat(m_rows, other.m_cols);
        for (size_t i = 0; i < m_rows; i++) {
            for (size_t j = 0; j < other.m_cols; j++) {
                newMat[i][j] = 0;
                for (size_t k = 0; k < m_cols; k++)
                    newMat[i][j] += m_mat[i][k] * other.m_mat[k][j];
            }
        }

        char* newName = constructName(other, '*');
        clear();
        m_mat = newMat;
        m_name = newName;
        m_cols = other.m_cols;
    }
    return *this;
}


Matrix& Matrix::operator*=(Matrix::elem_t scalar)
{
    for (size_t i = 0; i < m_rows; i++)
        for (size_t j = 0; j < m_cols; j++)
            m_mat[i][j] *= scalar;
    
    char* newName = constructName(scalar);
    delete[] m_name;
    m_name = newName;
    return *this;
}


Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.m_rows == rhs.m_rows && lhs.m_cols == rhs.m_cols)
        return Matrix(lhs) += rhs;

    return Matrix();
}


Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.m_cols == rhs.m_rows)
        return Matrix(lhs) *= rhs;

    return Matrix();
}


Matrix operator*(const Matrix& mat, Matrix::elem_t scalar)
{
    return Matrix(mat) *= scalar;
}


Matrix operator*(Matrix::elem_t scalar, const Matrix& mat)
{
    return Matrix(mat) *= scalar;
}


Matrix Matrix::operator~()
{
    char* newName = constructName('t');
    Matrix result(m_cols, m_rows, newName);
    delete[] newName;

    for (size_t i = 0; i < result.m_rows; i++)
        for (size_t j = 0; j < result.m_cols; j++)
            result.m_mat[i][j] = m_mat[j][i];

    return result;
}


int Matrix::determinant() const
{
    if (m_cols == m_rows) {
        switch (m_cols) {
            case 0:
                return 0;
            case 1:
                return m_mat[0][0];
            case 2:
                return m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
            case 3:
                return m_mat[0][0] * (m_mat[1][1] * m_mat[2][2] - m_mat[1][2] * m_mat[2][1]) +
                       m_mat[0][1] * (m_mat[1][2] * m_mat[2][0] - m_mat[1][0] * m_mat[2][2]) +
                       m_mat[0][2] * (m_mat[1][0] * m_mat[2][1] - m_mat[1][1] * m_mat[2][0]);
            default:
                return 0;
        }
    }

    return 0;
}


Matrix::elem_t** Matrix::initMat(size_t rows, size_t cols)
{
    elem_t** res = new Matrix::elem_t*[rows];
    for (size_t i = 0; i < rows; i++) {
        res[i] = new Matrix::elem_t[cols];
        for (size_t j = 0; j < cols; j++)
            res[i][j] = 0;
    }
    return res;
}


char* Matrix::constructName(const Matrix& other, char operation)
{
    size_t oldNameLen = strlen(m_name);
    // +4 = (1 for '(' + 1 for the operation + 1 for ')' + 1 for '\0')
    char* newName = new char[oldNameLen + strlen(other.m_name) + 4];
    strcpy(newName, "(");
    strcat(newName, m_name);
    newName[oldNameLen + 1] = operation;
    newName[oldNameLen + 2] = '\0';
    strcat(newName, other.m_name);
    strcat(newName, ")");
    return newName;
}


// Helper method to convert a scalar to string
size_t itoa(char* destination, size_t scalar)
{
    size_t scalarLen = 0;
    while (scalar > 0) {
        destination[scalarLen] = '0' + scalar % 10;
        scalar /= 10;
        ++scalarLen;
    }

    destination[scalarLen] = '\0';

    for (size_t i = 0; i <= scalarLen / 2; i++)
        destination[i] = destination[scalarLen - 1 - i];

    return scalarLen;
}


char* Matrix::constructName(Matrix::elem_t scalar)
{
    size_t scalarLen = log10(scalar) + 1;
    char* newName = new char[strlen(m_name) + scalarLen + 1];
    itoa(newName, scalar);
    strcat(newName, m_name);
    return newName;
}


char* Matrix::constructName(char transposeChar)
{
    size_t nameLen = strlen(m_name);
    char* newName = new char[nameLen + 2];
    strcpy(newName, m_name);
    newName[nameLen] = transposeChar;
    newName[nameLen + 1] = '\0';
    return newName;
}


void Matrix::copy(const Matrix& other)
{
    m_name = new char[strlen(other.m_name) + 1];
    strcpy(m_name, other.m_name);

    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_mat = initMat(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; i++)
        for (size_t j = 0; j < m_cols; j++)
            m_mat[i][j] = other.m_mat[i][j];
}


void Matrix::clearMatrix()
{
    for (size_t i = 0; i < m_rows; i++)
        delete[] m_mat[i];
    delete[] m_mat;
    m_mat = nullptr;
}


void Matrix::clear()
{
    delete[] m_name;
    m_name = nullptr;
    clearMatrix();
}

