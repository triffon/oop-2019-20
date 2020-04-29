#pragma once
#include "Eatable.h"

class Fruit : public Eatable {
    double calories;
    double protein;
    double carbohydrates;
    double fat;

public:
    Fruit(double = 0, double = 0, double = 0, double = 0, Taste = SWEET);
    double getCalories();
    double getFat();
    void print();
};
