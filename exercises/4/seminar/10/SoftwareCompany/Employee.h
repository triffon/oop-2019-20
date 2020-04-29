#pragma once
#include "Person.h"
class Employee : protected Person {
public:
	Employee(const Person& p, string email = "");

	void write(ostream& out) const;
private:
	string email;
};

ostream& operator<<(ostream& out, const Employee& e);

