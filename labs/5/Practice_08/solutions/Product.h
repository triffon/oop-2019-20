#pragma once
#include "Object.h"
#include "Classification.h"

class Product : public Object, public Classification {

public:
    Product(const char* = "unknown", float = 0, const char* = "unknown", int = 0, int = 0, int = 0, int = 0);

    double getVolumetriWeight();
    double getPricePerWeight();
    double getPricePerVolume();

    void print();
};
