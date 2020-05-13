#include <iostream>
using namespace std;

template <typename T>
T mmax(T& val1, T& val2) {
    return (val1 > val2) ? val1 : val2;
}

int main() {
    int a = 5, b = 6;
    cout<< mmax(a, b)<< endl;

    char d = 'a', c = 'z';
    cout<< mmax(d, c)<< endl;

    return 0;
}
