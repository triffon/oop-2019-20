#include <iostream>
using namespace std;

class Rational {
    int a;
    int b;

public:

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    Rational(int c, int d) {
        a = c;
        if(b == 0) {
            cout<< "initialization error. Setting b to 1";
            b = 1;
        } else {
            b = d;
        }
    }
};

int main () {
    Rational r1(5, 2), r2(1, 1);
    Rational r3;

    cout<< r3.getA()<< " "<< r3.getB()<< endl;

    return 0;
}



    /*
        [2] Rational() {}
        [3] Rational() = default;
        [4] Rational(int a, int b): a(a), b(b) {}

        [5] Rational(int a, int b): a(a), b(b) {
                if(b == 0) {
                    cout<< "initialization failed. Resetting b to 1"<< endl;
                    b = 1;
                }
             }

        [6] Rational(int a, int b) {
            this->a = a;
            if(b == 0) {
                cout<< "initialization error. Setting b to 1";
                this->b = 1;
            } else {
                this->b = b;
            }
        }
    */
