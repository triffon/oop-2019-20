#include <iostream>


struct ComplexNum {
    double imaginary;
    double real;
};


ComplexNum addComplexNums(ComplexNum num1, ComplexNum num2)
{
    ComplexNum result;
    result.imaginary = num1.imaginary + num2.imaginary;
    result.real = num1.real + num2.real;
    return result;
}


void print(ComplexNum num)
{
    std::cout << num.imaginary << 'i';

    if (num.real >= 0)
        std::cout << " + " << num.real;
    else
        std::cout << " - " << -num.real;
}


int main()
{
    ComplexNum compl1 = { 3, 5 };   // 3i + 5
    ComplexNum compl2;              // 4i - 7
    compl2.imaginary = 4;
    compl2.real = -7;

    print(compl1);
    std::cout << " + ";
    print(compl2);
    std::cout << " = ";
    ComplexNum res = addComplexNums(compl1, compl2);
    print(res);

    return 0;
}
