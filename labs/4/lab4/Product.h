#pragma once

class Product {
	char* name;
	char* manufacturerName;
	float price;
	int quantity;

	void init(const char* name, const char* manufacturerName, float price, int quantity);

public:
	Product(const char* name, const char* ownerName, float price, int quantity);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	void print();
};