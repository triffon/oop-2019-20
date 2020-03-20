#include <iostream>
#include "Rational.h"

int main()
{
    // Simple calculator
    std::cout << "This is a simple fraction calculator that accepts input of this type:" << std::endl;
    std::cout << "<fraction> <operation> <fraction>" << std::endl;
    std::cout << "Example: 1/2 + 2/3" << std::endl;
    std::cout << "To exit the program press Ctrl + C" << std::endl;

    for(;;) {
        char operation;
        Rational num1, num2, res;
        std::cin >> num1 >> operation >> num2;
        switch (operation) {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                res = num1 / num2;
                break;
            default:
                std::cout << "Unknown operation!" << std::endl;
                continue;
        }
        std::cout << num1 << " " << operation << " " << num2 << " = " << res;
        if (res.getDenominator() != 0 && res.getNumerator() != 0 && res.getDenominator() != 1)
            std::cout << " = " << (double)res;
        std::cout << std::endl;
    };

    return 0;
}
