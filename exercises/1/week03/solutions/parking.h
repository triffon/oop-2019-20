#pragma once
#include "car.h"
#include "person.h"

class Parking {

private:

	Car* cars;
	char* name;
	int capacity;
	int size;

	void copy(const Parking& p);

	void erase();

	void resize();

public:

	Parking();

	Parking(const Parking& p);

	Parking& operator=(const Parking& other);

	~Parking();

	int getSize() const;

	void setSize(const int size);

	const char* getName() const;

	void setName(const char* name);

	void addCar(const Car& c);

	void remove();

	void print();

	Person findOwner(const char* number);

	void printAllCarsOfOwner(const Person& p);
};

#include "parking.cpp"
