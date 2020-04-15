#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void readInts(int n, int * a) {
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

int arrayIntsMin(int n, int * a) {
    int min = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return min;
}

template <typename T>
void read(int n, T * a) {
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

template <typename T>
T arrayMin(int n, T * a) {
    T min = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return min;
}

template <typename T = double, typename S = int>
class A {

public:
    T f1(T t, S s) {
        cout << "f1(" << t << ", " << s << ")" << endl;
        return t;
    }
    S f2(T, S);

private:
    T a;
    S b;

};

template <typename T, typename S>
S A<T, S>::f2(T t, S s) {
    cout << "f2(" << t << ", " << s << ")" << endl;
    return s;
}

int main() {
    //int a[10];
    //read(3, a);
    //cout << "min = " << arrayMin(3, a) << endl;

    //double b[10];
    //read(3, b);
    //cout << "min = " << arrayMin(3, b) << endl;

    A<int, double> obj1;
    obj1.f1(1, 2.1);

    obj1.f2(1, 2.1);

    A<char> obj2;
    obj2.f1('a', 1);

    A<> obj3;
    obj3.f1(1.2, 2);

    typedef A<double, int> Adi;

    Adi obj4;
    obj4.f1(1.2, 2);

    typedef A<> A1;
    A1 obj5;
    obj5.f1(1.2, 2);

    return 0;
}