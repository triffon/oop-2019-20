#include "Car.h"
#include <iostream>
#include <cstring>

using namespace std;

void Car::copy(const Car& other)
{
	int manLength = strlen(other.manufacturer) + 1;
	int modelLength = strlen(other.modelName) + 1;
	this->modelName = new char[modelLength];
	strcpy_s(this->modelName, modelLength, other.modelName);
	strcpy_s(this->manufacturer, manLength, other.manufacturer);
	this->price = other.price;
}

Car::Car()
{
	manufacturer[0] = 0;
	modelName = nullptr;
	price = 0;
}

Car::Car(const char* manufacturer, const char* modelName, int price)
{
	int manLength = strlen(manufacturer) + 1;
	int modelLength = strlen(modelName) + 1;
	this->modelName = new char[modelLength];
	strcpy_s(this->modelName, modelLength, modelName);
	strcpy_s(this->manufacturer, manLength, manufacturer);
	this->price = price;
}

Car::Car(const Car& other)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this == &other) {
		return *this;
	}
	delete[] modelName;
	copy(other);
	return *this;
}

Car::~Car()
{
	delete[] modelName;
}

void Car::serialize(ofstream& fileOut) const
{
	int modelLen = strlen(modelName) + 1;
	fileOut << modelLen << endl
			<< modelName << endl
			<< manufacturer << endl << price << endl;
}

void Car::deserialize(ifstream& fileIn)
{
	delete[] modelName;
	int modelLen;
	fileIn >> modelLen;
	modelName = new char[modelLen];
	fileIn >> modelName >> manufacturer >> price;
	modelName[modelLen - 1] = 0;
}

void Car::print()
{
	cout << "Car:" << endl << "Manufacturer: " << manufacturer << endl
		<< "Model: " << modelName << endl << "Price: " << price << endl;
}
