#pragma once

#include "Car.h"

class Dealership
{

public:
	// ТHE BIG 4
	Dealership( size_t capacity = 8);
	Dealership( const Dealership& other );
	Dealership& operator=( const Dealership& other );
	~Dealership();

public:
	void addCar( const Car& newCar );
	void print() const;
	void readFromConsole();

private:
	void clean();
	void copyFrom(const Dealership& other);
	void resize( size_t newCapacity );
private:
	size_t fSize;
	size_t fCapacity;
	Car* fCars;
};

