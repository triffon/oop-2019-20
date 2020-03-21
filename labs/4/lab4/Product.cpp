#include <cstring>
#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(const char* name, const char* manufacturerName, float price, int quantity) {
	init(name, manufacturerName, price, quantity);
}

Product::Product(const Product& other) {
	init(other.name, other.manufacturerName, other.price, other.quantity);
}

Product& Product::operator=(const Product& other)
{
	if (this == &other) {
		return *this;
	}
	delete[] name;
	delete[] manufacturerName;
	init(other.name, other.manufacturerName, other.price, other.quantity);
	return *this;
}

Product::~Product()
{
	delete[] name;
	delete[] manufacturerName;
}

void Product::print()
{
	cout << "Name: " << name << endl;
	cout << "Manufacturer: " << manufacturerName << endl;
	cout << "Price: " << price << endl;
	cout << "Quantity: " << quantity << endl;
}

void Product::init(const char* name, const char* manufacturerName, float price, int quantity)
{
	this->name = new char[strlen(name) + 1];
	this->manufacturerName = new char[strlen(manufacturerName) + 1];
	strcpy(this->name, name);
	strcpy(this->manufacturerName, manufacturerName);
	this->price = price;
	this->quantity = quantity;
}