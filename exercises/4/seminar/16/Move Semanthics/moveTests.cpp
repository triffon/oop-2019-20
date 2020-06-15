#include <iostream>
using namespace std;

int& print(const int& x) {
    int& y = const_cast<int&>(x);
    y += 5;
    //cout<< y<< endl;

    return y;
}

const int& getV() {
    return 6;
}

int main() {
    int& x = print(5);
    cout<< x<< endl;

    const int& y = 7;
    int&& z = 7;
    const int& a = getV();
    //int&& b = z;

    return 0;
}
