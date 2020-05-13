#pragma once

#include <iostream>
#include "Vector.h"
#include "Employee.h"

using namespace::std;

class HR: public Employee {
public:
	HR(const Employee& employee, 
		Vector<Person*> potentialEmployees = Vector<Person*>(), 
		Vector<const char*> knownBuzzwords = Vector<const char*>());

	void addPotentialEmployee(Person* potentialEmployee);
	void addBuzzword(const char* buzzword);
	void giveAdvice();

private:
	Vector<Person*> potentialEmployees;
	Vector<const char*> knownBuzzwords;
};

