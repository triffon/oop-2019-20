#include <iostream>
#include "utils.h"
using namespace std;

void Person::copy(const Person& p) {
	this->age = p.age;
	this->hasDrivingLicense = p.hasDrivingLicense;
	this->name = copyDyn(p.name);
}

void  Person::erase() {
	if (this->name != nullptr) {
		delete[] this->name;
	}
}

Person::Person() {
	this->name = nullptr;
	this->age = 0;
	this->hasDrivingLicense = false;
}

Person::Person(const char* name, const int age, const bool hasDrivingLicense) {
	this->age = age;
	this->hasDrivingLicense = hasDrivingLicense;

	this->name = copyDyn(name);
}

 Person::Person(const Person& p) {
	copy(p);
}

Person&  Person::operator=(const Person& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

 Person::~Person() {
	erase();
}

bool  Person::operator==(const Person& p) {
	return strcmp(p.name, this->name) == 0 && (this->age == p.age) && (this->hasDrivingLicense == p.hasDrivingLicense);
}

const char*  Person::getName() const {
	if (this->name == nullptr) {
		return "N/A";
	}
	return this->name;
}

int  Person::getAge() const {
	return this->age;
}

bool  Person::getDrivingLicense() const {
	return this->hasDrivingLicense;
}

void  Person::setName(const char* name) {
	delete[] this->name;
	this->name = copyDyn(name);
}

void  Person::setAge(const int age) {
	this->age = age;
}

void  Person::setDrivingLicense(const bool hasDrivingLicense) {
	this->hasDrivingLicense = hasDrivingLicense;
}

void  Person::print() {
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Driving License: " << boolalpha << this->hasDrivingLicense << endl << endl;
}
