#include "Banana.h"

Banana::Banana(const char * category, double price, const char * barcode, int weight, int width, int length, int height, double calories, double protein, double carbohydrates, double fat, Taste taste) :
        Product(category, price, barcode, weight, width, length, height),
        Fruit(calories, protein, carbohydrates, fat, taste)
{}

double Banana::getPricePerCalories() {
    return getPrice() / getCalories();
}

double Banana::getFatWeight() {
    return getFat() / getWeight();
}

void Banana::print() {
    Fruit::print();
    Product::print();
}
