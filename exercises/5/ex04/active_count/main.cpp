#include <iostream>
#include "active_count.hpp"

void f() {
    std::cout << "f" << std::endl;
    ActiveCount a2;

    std::cout << ActiveCount::getInstancesCount() << std::endl;
}

int main() {
    std::cout << ActiveCount::getInstancesCount() << std::endl;

    ActiveCount a1;

    std::cout << "main" << std::endl;
    std::cout << ActiveCount::getInstancesCount() << std::endl;

    f();
    std::cout << "main" << std::endl;
    std::cout << ActiveCount::getInstancesCount() << std::endl;

    return 0;
}