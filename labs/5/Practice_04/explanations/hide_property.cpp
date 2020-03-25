/*
Проблем: скриване на член-данни от локални променливи
*/

#include <iostream>

using std::cout;
using std::endl;

class Test {
    int number;

public:
    Test() {
        // Грешно!
        int number = 3; 
        // Правилно 1: number = 3;
        // Правилно 2: this->number = 3;
    };

    Test(int number) {
        // Грешно!
        number = number;
        // Правилно: this->number = number;
    }

    void printNumber() {
        cout << number << endl;
    }
};

int main() {
    Test tmp;
    tmp.printNumber();

    Test tmp2(26);
    tmp2.printNumber();

    return 0;
}
