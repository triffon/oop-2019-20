#include <cassert>
#include "linearSystem.hpp"
#include "matrix.hpp"


LinearSystem::LinearSystem(const Matrix& m): m(m) {
	assert(m.getRowsCount() == m.getColsCount() - 1);
}

void LinearSystem::rightTriangle() {
    for (int row1 = 0; row1 < m.getRowsCount(); ++row1) {
        int correctRow = row1;
        for (; m[correctRow][row1].getA() == 0 && correctRow < m.getRowsCount(); ++correctRow);
        assert(correctRow < m.getRowsCount());
        if (correctRow != row1) {
            Vector temp = m[row1];
            m[row1] = m[correctRow];
            m[correctRow] = temp;
        }

        for (int row2 = row1 + 1; row2 < m.getRowsCount(); ++row2) {
            Rational d = -(m[row2][row1] / m[row1][row1]);
            m[row2] += m[row1] * d;
        }
    }
}

Vector LinearSystem::getSolution() {
    rightTriangle();
    Vector result;
    result.reserve(m.getRowsCount());

    for (int row = m.getRowsCount() - 1; row >= 0; --row) {
        result[row] = m[row][m.getColsCount() - 1];
        for (int col = row + 1; col < m.getRowsCount(); ++col) {
            result[row] -= m[row][col] * result[col];
        }
        result[row] /= m[row][row];
    }

    return result;
}

