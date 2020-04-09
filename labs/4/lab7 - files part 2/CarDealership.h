#pragma once
#include "Car.h"
#include <fstream>

const int MAX_SIZE = 10;

class CarDealership
{
	Car cars[MAX_SIZE];
	int currentLength;
public:
	CarDealership();
	bool addCar(const Car& car);
	void serialize(ofstream& fileOut) const;
	void deserialize(ifstream& fileIn);
	void print();
};

