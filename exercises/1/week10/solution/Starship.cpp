#include "Starship.h"
#include <iostream>
#include <cstring>
using namespace std;

Starship::Starship(const char *_type, int _weight_in_tons)
	:weight_in_tons(_weight_in_tons)
{
	type = new char[strlen(_type) + 1];
	strcpy(type, _type);
	cout << "Creating: " << type << endl;
}


void Starship::printType()
{
	if (type != nullptr)
	{
		cout << "Ship type:" << type << endl;
	}
}

Starship::~Starship()
{
	if (type != nullptr)
	{
		delete[] type;
	}
}