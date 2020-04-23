#include <iostream>
#include "Fruit.h"

using std::cout;
using std::endl;

Fruit::Fruit(double calories, double protein, double carbohydrates, double fat, Taste taste) : Eatable(taste) {
    this->calories = calories;
    this->protein = protein;
    this->carbohydrates = carbohydrates;
    this->fat = fat;
}

double Fruit::getCalories() {
    return calories;
}

double Fruit::getFat() {
    return fat;
}

void Fruit::print() {
    Eatable::print();
    cout << "Calories: " << calories << "\nProtein: " << protein << "\nCarbohydrates: " << carbohydrates << "\nFat: " << fat << "\n";
}
