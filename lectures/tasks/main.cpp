#include <iostream>

#include "quicktask.hpp"

void testQuickTask() {
    QuickTask trash("изхвърляне на боклука");
    trash.print();std::cout << std::endl;
    trash.work();
    trash.print();std::cout << std::endl;
}

int main() {
    testQuickTask();
}