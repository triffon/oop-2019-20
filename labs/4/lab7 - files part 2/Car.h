#pragma once
#include <fstream>
using namespace std;

class Car
{
	char* modelName;
	char manufacturer[20];
	int price;

	void copy(const Car& other);

public:
	Car();
	Car(const char* manufacturer, const char* modelName, int price);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();

	void serialize(ofstream& fileOut) const;
	void deserialize(ifstream& fileIn);

	void print();
};
