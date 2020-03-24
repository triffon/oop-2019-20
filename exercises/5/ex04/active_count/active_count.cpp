#include <iostream>
#include "active_count.hpp"

int ActiveCount::instancesCount = 0;

ActiveCount::ActiveCount() {
    std::cout << "ActiveCount" << std::endl;
    ++instancesCount;
}

ActiveCount::~ActiveCount() {
    std::cout << "~ActiveCount" << std::endl;
    --instancesCount;
}

int ActiveCount::getInstancesCount() {
    return instancesCount;
}