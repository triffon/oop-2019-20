// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "rational.hpp"
#include "matrix.hpp"
#include "linearSystem.hpp"
using namespace std;

int main() {

    Matrix m1;

    ifstream fi("C:\\Users\\dtrz\\Desktop\\input.txt");
    if (!fi.good()) {
        cout << "file reading broken, try again.";
        return 1;
    }

    fi >> m1;
    fi.close();

    LinearSystem ls(m1);


    ofstream fo("C:\\Users\\dtrz\\Desktop\\output.txt");

    fo << m1 << "-------------------------\n";
    Vector res = ls.getSolution();
    for (int i = 0; i < 3; ++i) {
        fo << res[i]<< " ";
    }
    fo << endl;
    fo.close();

    fo.open("C:\\Users\\dtrz\\Desktop\\bin.txt", (ios::out | ios::binary));

    cout << m1<< endl;
    int rows = m1.getRowsCount();
    int cols = m1.getColsCount();
    fo.write((char*)&rows, sizeof(int));
    fo.write((char*)&cols, sizeof(int));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fo.write((char*)&(m1[i][j]), sizeof(Rational));
        }
    }

    fo.close();


    fi.open("C:\\Users\\dtrz\\Desktop\\bin.txt", (ios::in | ios::binary));

    rows = 0;
    cols = 0;
    fi.read((char*)&rows, sizeof(int));
    fi.read((char*)&cols, sizeof(int));
    Matrix m2(nullptr, 0, 0);
    m2.reserve(rows, cols);
    Rational r2;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fi.read((char*)&r2, sizeof(Rational));
            m2[i][j] = r2;
        }
    }
    cout << m2;
    cout << endl;

    fi.close();



    fi.open("C:\\Users\\dtrz\\Desktop\\bin.txt", (ios::in | ios::binary));

    fi.seekg(fi.tellg(), ios::beg + 2 * sizeof(int) + 2 * sizeof(Rational));
    fi.read((char*)&r2, sizeof(Rational));

    fi.close();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
