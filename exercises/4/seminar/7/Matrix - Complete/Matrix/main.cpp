// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "utility.hpp"
#include "rational.hpp"
#include "vector.hpp"
#include "matrix.hpp"
#include "linearSystem.hpp"
using namespace std;

int main() {
    /*Rational data[] = {
        Rational(0), Rational(0), Rational(3), Rational(3),
        Rational(3), Rational(-4), Rational(7), Rational(6),
        Rational(2), Rational(0), Rational(2), Rational(4)
    };
    Matrix m1(data, 3, 4);

    //cin >> m1;
    cout << "---------- system solution ----------\n";
    LinearSystem ls(m1);
    cout<< ls.getSolution()<< endl;
    cout << ls << "---------- \\system solution ----------\n";

    cout << "----------- addition ---------\n";
    Matrix m2 = m1;
    cout << m1 + m2 << endl;
    cout << "----------- \\addition ---------\n";

    cout << "----------- multiplication ---------\n";
    Rational d2[] = {
        Rational(1), Rational(0), Rational(0), 
        Rational(0), Rational(1), Rational(0), 
        Rational(0), Rational(0), Rational(1), 
        Rational(0), Rational(0), Rational(0)
    };
    Matrix m3(d2, 4, 3);
    cout << m1 * m3 << endl;
    cout << "----------- \\multiplication ---------\n";*/

    Matrix m1;

    ifstream f("C:\\Users\\dtrz\\Desktop\\input.txt");
    cout << "reading" << endl;
    f >> m1;
    cout << "read" << endl;
    f.close();

    cout << m1;

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
