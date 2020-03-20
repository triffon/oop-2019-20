#include <iostream>
#include "utils.h"
using namespace std;

void Car::copy(const Car& c) {
	this->model = copyDyn(c.model);
	this->number = copyDyn(c.number);
	this->color = copyDyn(c.color);
	this->owner = c.owner;
}

void Car::erase() {
	if (this->model != nullptr) {
		delete[] model;
	}

	if (this->number != nullptr) {
		delete[] number;
	}

	if (this->color != nullptr) {
		delete[] color;
	}
}


Car::Car() : owner() {
	this->model = nullptr;
	this->number = nullptr;
	this->color = nullptr;
}

Car::Car(const char* model, const char* number, const char* color, const Person& p) : owner(p) {
	this->model = copyDyn(model);
	this->number = copyDyn(number);
	this->color = copyDyn(color);
} 

Car::Car(const Car& c) {
	copy(c);
}

Car& Car::operator=(const Car& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Car::~Car() {
	erase();
}

const char* Car::getModel() const {

	return this->model;
}

const char* Car::getNumber() const {

	return this->number;
}

const char* Car::getColor() const {

	return this->color;
}

Person Car::getOwner() const {

	return this->owner;
}

void Car::setModel(const char* model) {

	delete[] this->model;
	this->model = copyDyn(model);
}

void Car::setNumber(const char* number) {

	delete[] this->number;
	this->number = copyDyn(number);
}

void Car::setColor(const char* color) {

	delete[] this->color;
	this->color = copyDyn(color);
}

bool Car::hasOwnerDrivingLicense() {

	return this->owner.getDrivingLicense();
}

void Car::print() {
	cout << "Model: " << this->model << endl;
	cout << "Number: " << this->number << endl;
	cout << "Color: " << this->color << endl;
	cout << "Owne: " << endl;
	this->owner.print();
	cout << endl;
}
