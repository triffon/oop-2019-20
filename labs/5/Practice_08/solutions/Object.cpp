#include <iostream>
#include "Object.h"

using std::cout;
using std::endl;

Object::Object(int weight, int width, int length, int height) {
    this->weight = weight;
    this->width = width;
    this->length = length;
    this->height = height;
}

double Object::getVolumetriWeight() {
    return ((double) weight) / (width * height * length);
}

double Object::getVolume() {
    return ((double) weight) / (width * height * length);
}

int Object::getWeight() {
    return weight;
}

void Object::print() {
    cout << "Weight: " << weight << "\nWidth: " << width << "\nLength: " << length << "\nHeight: " << height << endl;
}
