#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<int> v;
    for (int i = 0; i < 15; ++i) {
        v.append(i);
    }

    for (int i = 0; i < 15; ++i) {
        cout << v[i]<< " ";
    }

    return 0;
}
