#include "CarDealership.h"
#include <iostream>

using namespace std;

CarDealership::CarDealership()
{
	currentLength = 0;
}

bool CarDealership::addCar(const Car& car)
{
	if (currentLength == MAX_SIZE)
		return false;
	cars[currentLength++] = car;
	return true;
}

void CarDealership::serialize(ofstream& fileOut) const
{
	fileOut << currentLength <<endl;
	for (int carIdx = 0; carIdx < currentLength; ++carIdx) {
		cars[carIdx].serialize(fileOut);
	}
}

void CarDealership::deserialize(ifstream& fileIn)
{
	fileIn >> currentLength;
	for (int carIdx = 0; carIdx < currentLength; ++carIdx) {
		cars[carIdx].deserialize(fileIn);
	}
}

void CarDealership::print()
{
	cout << "Car dealership:" << endl
		<< "Number of cars: " << currentLength << endl;
	for (int idx = 0; idx < currentLength; ++idx) {
		cars[idx].print();
	}
}
