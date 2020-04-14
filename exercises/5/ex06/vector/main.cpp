#include <iostream>

#include "vector.hpp"

using std::cout;
using std::endl;

template <typename T>
void sort(Vector<T> & v, int (*cmp)(T const &, T const &)) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (cmp(v[i], v[j]) > 0) {
                T tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

int cmpMin(double const & t1, double const & t2) {
    if (t1 < t2) return -1;
    if (t1 > t2) return 1;
    return 0;
}

int cmpMax(double const & t1, double const & t2) {
    if (t1 < t2) return 1;
    if (t1 > t2) return -1;
    return 0;
}

int main() {
    Vector<int> v1;
    cout << v1.size() << endl;

    for (int i = 0; i < 100; ++i) {
        v1.push(i);
    }

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << ' ';
    }
    cout << endl;

    v1.resize(32);
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << ' ';
    }
    cout << endl;

    Vector<int> v2(8);
    for (int i = 0; i < 8; ++i) {
        v2[i] = 2 * i;
    }

    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << ' ';
    }
    cout << endl;

    cout << cmpMin(1, 10) << ' ' << cmpMin(1, 1) << ' ' << cmpMin(10, 1) << endl;
    cout << cmpMax(1, 10) << ' ' << cmpMax(1, 1) << ' ' << cmpMax(10, 1) << endl;

    typedef Vector<double> Vdouble;

    Vdouble v3;
    v3.push(10);
    v3.push(8);
    v3.push(8.1);
    v3.push(7);
    v3.push(7.5);

    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << ' ';
    }
    cout << endl;

    sort(v3, cmpMin);
    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << ' ';
    }
    cout << endl;

    sort(v3, cmpMax);
    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << ' ';
    }
    cout << endl;

    return 0;
}