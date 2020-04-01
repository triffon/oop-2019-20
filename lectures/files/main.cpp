#include <iostream>

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
    testSafeRead();
    return 0;
}