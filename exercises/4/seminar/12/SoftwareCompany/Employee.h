#pragma once
#include "Person.h"
class Employee : protected Person {
public:
	Employee(const Person& p = Person("name1", "name2", 42), double salary = 800, string email = "");

	void write(ostream& out) const;
private:
	double salary;
	string email;
};

ostream& operator<<(ostream& out, const Employee& e);

