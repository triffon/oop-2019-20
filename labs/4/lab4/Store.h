#pragma once
#include "Product.h"

const int DEFAULT_CAPACITY = 5;

class Store {
	Product** products;
	int maximumCapacity;
	int currentCapacity;

	void deleteStore();
	void copy(const Store& other);
public:
	Store();
	Store(int capacity);
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	void print();

	// For exercise - implement the next 5 methods
	bool updateQuantity(const char* productName, const char* manufacturerName);
	bool buy(const char* productName, const char* manufacturerName);

	bool listAvailableProducts();
	bool listManufacturerProducts(const char* manufacturerName);
	bool removeProduct(const char* name, const char* manufacturerName);

	// Method overloading - we have 2 methods with the same name
	// but different signature, the compiler will choose the right method
	// depending on the arguments given to addProduct
	bool addProduct(const Product& p);
	bool addProduct(const char* name, const char* manufacturerName, float price, int quantity);
};