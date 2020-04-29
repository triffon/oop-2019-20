#pragma once
#include "Fruit.h"
#include "Product.h"

class Banana : public Fruit, public Product {
public:
    Banana(const char* = "", double = 0, const char* = "", int = 0, int = 0, int = 0, int = 0, double = 0, double = 0, double = 0, double = 0, Taste = SWEET);

    double getPricePerCalories();
    double getFatWeight();

    void print();
};
