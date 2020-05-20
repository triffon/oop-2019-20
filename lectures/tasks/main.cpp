#include <iostream>

#include "quicktask.hpp"

void testQuickTask() {
    QuickTask trash("изхвърляне на боклука");
    std::cout << trash;
    trash.work();
    std::cout << trash;
}

int main() {
    testQuickTask();
}