#include <iostream>
#include <iomanip>
#include <fstream>

void printTextFile(char const* filename) {
    std::ifstream fi(filename);
    const int MAX = 1000;
    char line[MAX] = "";
    unsigned counter = 0;
    while (fi.getline(line, MAX))
        std::cout << ++counter << ": " << line << std::endl;
}

void printBinaryFile(char const* filename) {
    std::ifstream fi(filename, std::ios::in | std::ios::binary);
    const int MAX = 1000;
    char byte = 0; // [-128; 127]
    // unsigned char: [0; 255]
    unsigned counter = 0;
    while (fi.get(byte))
        std::cout << std::dec << ++counter << ": " << std::hex << (int)(unsigned char)byte << std::endl;
}

void writeBottlesSong(char const* filename, int bottles = 10) {
    std::ofstream fo(filename);
    for(; bottles > 0; bottles--)
        fo << "There are " << bottles << " green bottles hanging on the wall,\n"
           << "there are " << bottles << " green bottles hanging on the wall,\n"
           << "and if one green bottle accidentally falls\n"
           << "there will be " << bottles - 1 << " green bottles hanging on the wall!\n\n";
}

void countInBinary(char const *filename, int to = 10, int from = 0) {
    std::ofstream fo(filename, std::ios::out | std::ios::binary);
    for(char i = from; i <= to; i++)
        fo.put(i);
}

bool safeReadInt(int& x, std::istream& is = std::cin) {
    std::cout << "Моля, въведете цяло число: ";
    is >> x;
    while (!is) {
        if (is.rdstate() & (std::ios::badbit | std::ios::eofbit)) {
            std::cerr << "Възникна фатална грешка!" << std::endl;
            return false;
        }
        std::clog << "is.rdstate() = " << is.rdstate() << std::endl;
        is.clear();
        is.get(); // изхвърляме проблемния символ
        std::clog << "is.rdstate() = " << is.rdstate() << std::endl;
        is >> x;
        std::clog << "is.rdstate() = " << is.rdstate() << std::endl;
    }
    return true;
}

void testistream() {
    int x;
    std::cin >> x;
    std::cout << "std::cin.good() = " << std::cin.good() << std::endl;
    std::cout << "std::cin.bad() = " << std::cin.bad() << std::endl;
    std::cout << "std::cin.eof() = " << std::cin.eof() << std::endl;
    std::cout << "std::cin.fail() = " << std::cin.fail() << std::endl;
    std::cout << "std::cin.rdstate() = " << std::cin.rdstate() << std::endl;
}

void testSafeRead() {
    int x = 0; // инициализиране на числото
    if (safeReadInt(x))
        std::cout << "Успешно прочетено число: " << x << std::endl;
    else
        std::cout << "Неуспешно прочитане на числото" << std::endl;
}

int main() {
//    testistream();
    // testSafeRead();
    // printTextFile("main.cpp");
    // printBinaryFile("build/files");
    // writeBottlesSong("bottles10.txt");
    // writeBottlesSong("bottles100.txt", 100);
    countInBinary("numbers.bin", 100);
    countInBinary("numbers.bin", 50, 30);
    printBinaryFile("numbers.bin");
    return 0;
}