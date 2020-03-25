#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Test {
    int number;

public:
    Test() {}

    void read() {
        cout << "Enter number:";
        cin >> number;
    }
};

int main() {
    int n;
    Test* numbers = new Test[8];

    cout << "Enter count of number to read:";
    cin >> n;

    if (n > 8) {
        delete numbers;
        numbers = new Test[n];
    }

    return 0;
}
