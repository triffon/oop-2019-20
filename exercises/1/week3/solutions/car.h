#pragma once
#include "person.h"

class Car {

private:
	char* model;
	char* number;
	char* color;
	Person owner;

	void copy(const Car& c);

	void erase();

public:

	Car();

	Car(const char* model, const char* number, const char* color, const Person& p);

	Car(const Car& c);

	Car& operator=(const Car& other);

	~Car();
	
	const char* getModel() const;

	const char* getNumber() const;

	const char* getColor() const;

	Person getOwner() const;

	void setModel(const char* model);

	void setNumber(const char* number);

	void setColor(const char* color);

	bool hasOwnerDrivingLicense();

	void print();
};

#include "car.cpp"

