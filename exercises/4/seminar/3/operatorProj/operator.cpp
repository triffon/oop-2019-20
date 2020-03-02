#include <iostream>
#include "operator.h"
using namespace std;

int main () {
    Number x {7}, y {5};
    cout<< (x+y).val<< endl;

    return 0;
}
