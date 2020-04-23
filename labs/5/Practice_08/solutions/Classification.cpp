#include <iostream>
#include <cstring>
#include "Classification.h"

using std::cout;
using std::endl;

Classification::Classification(const char * category, double price, const char * barcode) : price(price) {
    this->category = new char[strlen(category) + 1];
    strcpy(this->category, category);

    this->barcode = new char[strlen(barcode) + 1];
    strcpy(this->barcode, barcode);
}

double Classification::getPrice() {
    return price;
}

void Classification::print() {
    cout << "Category: " << category << "\nPrice: " << price << "\nBarcode: " << barcode << endl;
}

Classification::~Classification() {
    delete [] category;
    delete [] barcode;
}
