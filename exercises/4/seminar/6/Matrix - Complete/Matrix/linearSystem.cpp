#include <cassert>
#include "linearSystem.hpp"

LinearSystem::LinearSystem(const Matrix& m) : m(m) {
    assert(m.getRowCount() > 1);
    assert(m.getRowCount() == m.getColCount() - 1);
}

void LinearSystem::rightTriangle() {

    for (int row1 = 0; row1 < m.getRowCount(); ++row1) {
        for (int row2 = row1 + 1; row2 < m.getRowCount(); ++row2) {
            for (int col = row1 + 1; m[row1][row1].getA() == 0 && col < m.getColCount(); ++col) {
                if (m[row1][col].getA() != 0) {
                    Rational* temp = m[row1];
                    m[row1] = m[col];
                    m[col] = temp;
                }
            }
            assert(m[row1][row1].getA() != 0);
            Rational d = -(m[row2][row1] / m[row1][row1]);
            for (int col = row1; col < m.getColCount(); ++col) {
                m[row2][col] += d * m[row1][col];
            }
        }
    }
}

Rational* LinearSystem::getSolution() {
    Rational* result = new Rational[m.getRowCount()];

    rightTriangle();
    for (int row = m.getRowCount() - 1; row >= 0; --row) {
        result[row] = m[row][m.getColCount() - 1];
        for (int col = row + 1; col < m.getRowCount(); ++col) {
            result[row] -= m[row][col] * result[col];
        }
        result[row] /= m[row][row];
    }

    return result;
}

void LinearSystem::print(ostream& out) const {
    for (int row = 0; row< m.getRowCount(); ++row) {
        cout << "| (" << (m[row][0]) << ")" << "x" << row << " ";
        for (int col = 1; col< m.getColCount() - 1; ++col) {
            cout << " + (" << (m[row][col]) << ")" << "x" << row << " ";
        }
        cout << "= " << m[row][m.getColCount() - 1] << endl;
    }
}

void LinearSystem::read(istream& in) {
    in >> m;
}

ostream& operator<<(ostream& out, const LinearSystem& ls) {
    ls.print(out);
    return out;
}

istream& operator>>(istream& in, LinearSystem& ls) {
    ls.read(in);
    return in;
}