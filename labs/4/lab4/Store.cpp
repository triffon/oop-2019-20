#include <iostream>
#include "Store.h"

using namespace std;

Store::Store()
{
	maximumCapacity = DEFAULT_CAPACITY;
	products = new Product*[DEFAULT_CAPACITY];
	currentCapacity = 0;
}

Store::Store(int maximumCapacity)
{
	products = new Product*[maximumCapacity];
	this->maximumCapacity = maximumCapacity;
	currentCapacity = 0;
}

Store::Store(const Store& other)
{
	copy(other);
}

Store& Store::operator=(const Store& other)
{
	if (this == &other) {
		return *this;
	}
	deleteStore();
	copy(other);
	return *this;
}

Store::~Store()
{
	deleteStore();
}

void Store::deleteStore() {
	for (int idx = 0; idx < currentCapacity; ++idx) {
		delete products[idx];
	}
	delete[] products;
}

void Store::copy(const Store& other)
{
	products = new Product*[other.maximumCapacity];
	for (int idx = 0; idx < other.currentCapacity; ++idx) {
		products[idx] = new Product(*other.products[idx]);
	}
	maximumCapacity = other.maximumCapacity;
	currentCapacity = other.currentCapacity;
}

void Store::print()
{
	cout << "Store" << endl;
	for (int idx = 0; idx < currentCapacity; ++idx) {
		cout << "Product " << idx << endl;
		products[idx]->print();
		cout << endl;
	}
}

bool Store::addProduct(const Product& p)
{
	if (currentCapacity == maximumCapacity) {
		return false;
	}
	products[currentCapacity++] = new Product(p);
	return true;
}

bool Store::addProduct(const char* name, const char* manufacturerName, float price, int quantity)
{
	if (currentCapacity == maximumCapacity) {
		return false;
	}
	products[currentCapacity++] = new Product(name, manufacturerName, price, quantity);
	return true;
}

bool Store::updateQuantity(const char* productName, const char* manufacturerName)
{
	return false;
}

bool Store::buy(const char* productName, const char* manufacturerName)
{
	return false;
}

bool Store::listAvailableProducts()
{
	return false;
}

bool Store::listManufacturerProducts(const char* manufacturerName)
{
	return false;
}

bool Store::removeProduct(const char* name, const char* manufacturerName)
{
	return false;
}
