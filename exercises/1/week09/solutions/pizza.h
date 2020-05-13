#pragma once
#include <string>

class Pizza : public Food {
private:
	string type;

public:
	Pizza(const string type = "N/A",
		const int weight = 450, const int parts = 8, 
		const double price = 6.5);

	void print();

	void category();

	Food* clone();
};


#include "pizza.cpp"