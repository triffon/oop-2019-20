//
// Created by yasen on 2/22/20.
//

#include <iostream>
#include <cstring>
#include "Product.h"


void printProduct(const Product& product) {
    std::cout << "Description: " << product.description
              << "\t, Serial Number: " << product.serialNumber
              << "\t, Cost: " << product.cost << std::endl;
}
void init(Product& product, const char* newDesc, unsigned newSerialNumber, double newCost) {
    strcpy(product.description, newDesc);
    product.serialNumber = newSerialNumber;
    product.cost = newCost;
}

