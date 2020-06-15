#include <iostream>
using namespace std;

int main() {

    // statement = expression;
    4;
    4+5;
    (4+5)*9;
    ((4+5)*6)-(9/2)+17-10;

    // if expression then statement else statement
    if(true) {
        4+5;
    } else {
        (4+5)*9;
    }

    // loops are statements
    int i = 10;
    while(i > 0) {
        i+4;
        --i; // expression that returns i-1 and mutates i
    }

    // = is an operator that returns an expression
    int x = 3, y = 7;
    //         2*3 = 6
    x = (y += (2*x)) + 5;

    cout<< x<< " "<< y<< endl;

    return 0;
}
