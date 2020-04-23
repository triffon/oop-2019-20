#include <iostream>
#include "Product.h"

Product::Product(const char * category, float price, const char * barcode, int weight, int width, int length, int height) :
		Classification(category, price, barcode),
		Object(weight, width, length, height) {}

double Product::getPricePerWeight() {
    return getPrice() / getWeight();
}

double Product::getPricePerVolume() {
    return getPrice() / getVolume();
}

void Product::print() {
    Classification::print();
    Object::print();
}
