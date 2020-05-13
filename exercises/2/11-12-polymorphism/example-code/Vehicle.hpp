#pragma once

#include <iostream>

class Vehicle
{
public:
    virtual void drive() {
        std::cout << "Vehicle driven\n";
    }

    virtual Vehicle* clone() const = 0;

    virtual ~Vehicle() = default;
};
