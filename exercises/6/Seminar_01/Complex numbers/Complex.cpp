#include "Complex.hpp"

Complex add(Complex n, Complex m)
{
    Complex result;

    result.real = n.real + m.real;
    result.imaginary = n.imaginary + m.imaginary;

    return result;
}

Complex multiply(Complex n, Complex m)
{
    Complex result;

    result.real = (n.real * m.real) - (n.imaginary * m.imaginary);
    result.imaginary = (n.real * m.imaginary) + (n.imaginary * m.real);

    return result;
}

void print(Complex n)
{
    char sign = n.imaginary >= 0 ? '+' : '-';

    // If console prints negative sign, use string literal
    // const char* sign = n.imaginary >= 0 ? "+" : "";

    std::cout << n.real << sign << n.imaginary << "i" << std::endl;
}