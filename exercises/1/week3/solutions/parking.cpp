#include <iostream>
#include "utils.h"
using namespace std;

void Parking::copy(const Parking& p) {
	this->capacity = p.capacity;
	this->size = p.size;
	this->name = copyDyn(p.name);

	this->cars = new Car[this->capacity];

	for (int i = 0; i < this->size; i++) {
		this->cars[i] = p.cars[i];
	}
}

void Parking::erase() {
	if (this->name != nullptr) {
		delete[] this->name;
	}

	delete[] cars;
}

void Parking::resize() {
	this->capacity *= 2;
	Car* temp = this->cars;
	this->cars = new Car[this->capacity];

	for (int i = 0; i < this->size; i++) {
		this->cars[i] = temp[i];
	} 

	delete[] temp;
}

Parking::Parking() {
	this->size = 0;
	this->capacity = 4;
	this->name = nullptr;
	this->cars = new Car[capacity];
}

Parking::Parking(const Parking& p) {
	copy(p);
}

Parking& Parking::operator=(const Parking& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Parking::~Parking() {
	erase();
}

int Parking::getSize() const {

	return this->size;
}

void Parking::setSize(const int size) {

	this->size = size;
}

const char* Parking::getName() const {
	return this->name;
}

void Parking::setName(const char* name) {
	delete[] this->name;
	this->name = copyDyn(name);
}

void Parking::addCar(const Car& c) {
	if (this->size >= this->capacity) {
		resize();
	}
	this->cars[this->size] = c;
	this->size++;
}

void Parking::remove() {
	this->cars[this->size - 1] = Car();
	this->size--;
}

void Parking::print() {
	for (int i = 0; i < this->size; i++) {
		cars[i].print();
	}
}

Person Parking::findOwner(const char* number) {
	for (int i = 0; i < this->size; i++) {
		if (strcmp(number, cars[i].getNumber()) == 0) {
			return cars[i].getOwner();
		}
	}

	return Person();
} 

void Parking::printAllCarsOfOwner(const Person& p) {
	for (int i = 0; i < this->size; ++i) {
		if (cars[i].getOwner() == p) {
			cars[i].print();
		}
	}
}
