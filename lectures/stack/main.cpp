#include <iostream>
#include <cassert>
#include "stack.hpp"

char toDigit(unsigned digit) {
    if (digit < 10)
        return '0' + digit;
    else
        return 'A' + (digit - 10);
}

void printInK(unsigned n, unsigned k) {
    if (n == 0) {
      std::cout << 0;
    } else {
        Stack s;
        while (n > 0) {
            s.push(n % k);  // добавяме поредния остатък в стека
            n /= k;
        }
        while (!s.empty())
            std::cout << toDigit(s.pop());
    }
}

void testConvertToK() {
    unsigned n;
    std::cout << "Моля, въведете n: ";
    std::cin >> n;
    std::cout << "Моля, въведете бройна система: ";
    unsigned k;
    std::cin >> k;
    assert(k >= 2); // !!!
    std::cout << n << "(10) = ";
    printInK(n, k);
    std::cout << "(" << k << ")" << std::endl;
    // 42(10) = 101010(2)
}

int main() {
    testConvertToK();
    return 0;
}