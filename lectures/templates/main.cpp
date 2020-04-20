#include <iostream>
#include "rational.hpp"
#include "rational_point.hpp"
#include <cstring>

template <typename T>
void f(T a, int b) {
    std::cout << a << ' ' << b << std::endl;
    // std::cout >> a; // !!!
}

void f(char const* a, int b) {
    std::cout << "[" << a << "] " << b << std::endl;
}

template <typename T>
unsigned readArray(T a[]) {
    unsigned count = 0;
    char more = 'n';
    do {
        std::cout << "Моля, въведете елемент: ";
        std::cin >> a[count++];
        std::cout << "Още елементи [y/n]? ";
        std::cin.get(more); // игнорираме новия ред
        std::cin.get(more);
    } while (more == 'y' || more == 'Y');
    return count;
}

template <typename T>
void printArray(T a[], unsigned n) {
    for(int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

template <typename T>
unsigned countOccurrences(T a[], unsigned n, T const& x) {
    unsigned count = 0;
    for(int i = 0; i < n; i++)
        if (a[i] == x)
            count++;
    return count;
}

unsigned countOccurrences(char a[][30], unsigned n, char x[30]) {
    std::clog << "Сравняваме низове със strcmp" << std::endl;
    unsigned count = 0;
    for(int i = 0; i < n; i++)
        if (strcmp(a[i], x) == 0)
            count++;
    return count;
}

template <typename T>
void readPrintAndCount(T* a, char const* what) {
    std::cout << "Моля, въведете масив от " << what << ": " << std::endl;
    unsigned count = readArray(a);
    printArray(a, count);
    T x;
    std::cout << "Въведете елемент за търсене:" << std::endl;
    std::cin >> x;
    std::cout << "Елементът " << x << " се среща " << countOccurrences(a, count, x) << " брой пъти" << std::endl;
}

void testArray() {
    int a[10];
    readPrintAndCount(a, "цели числа");

    char b[20][30];
    readPrintAndCount(b, "думи");

    Rational c[5];
    readPrintAndCount(c, "рационални числа");
    /*
    RationalPoint d[5];
    std::cout << "Моля, въведете масив от рационални точки:" << std::endl;
    printArray(d, readArray(d));
    */
}

void testFunctionTemplates() {
    std::cout << "Hello world!\n";
    f<int>(5, 3);
    f("abc", 10);
    f<char const*>("abc", 10);
}

int main() {
    // testFunctionTemplates();
    testArray();
    return 0;
}