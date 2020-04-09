#pragma once
#include <iostream>

class Matrix
{
public:
    // Defining the type of our matrix's elements
    using elem_t = int;

    // Big four
    Matrix(size_t rows = 0, size_t cols = 0, const char* name = "unnamed");
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    // Operators
    const elem_t* operator[](size_t index) const { return m_mat[index]; }
    elem_t* operator[](size_t index) { return m_mat[index]; }
    friend std::istream& operator>>(std::istream& in, Matrix& obj);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& obj);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(elem_t scalar);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& mat, elem_t scalar);
    friend Matrix operator*(elem_t scalar, const Matrix& mat);
    Matrix operator~();

    // Getters
    inline size_t rows() const { return m_rows; }
    inline size_t cols() const { return m_cols; }
    inline const char* name() const { return m_name; }
    int determinant() const;

private:
    // Helper methods
    elem_t** initMat(size_t rows, size_t cols);
    char* constructName(const Matrix& other, char operation);
    char* constructName(elem_t scalar);
    char* constructName(char transposeChar);
    void copy(const Matrix& other);
    void clearMatrix();
    void clear();

    // Members
    elem_t** m_mat;
    char* m_name;
    size_t m_rows;
    size_t m_cols;
};
