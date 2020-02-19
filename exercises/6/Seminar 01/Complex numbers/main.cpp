#include "Complex.hpp"

void addComplexNumbersExample();
void multiplyComplexNumbersExample();

int main()
{
    addComplexNumbersExample();
    multiplyComplexNumbersExample();

    return 0;
}

void addComplexNumbersExample()
{
    Complex n = {1, 2};
    Complex m = {5, -3};

    Complex result = add(n, m);

    print(result);
}

void multiplyComplexNumbersExample()
{
    Complex n = {1, 2};
    Complex m = {1, -2};

    Complex result = multiply(n, m);

    print(result);
}