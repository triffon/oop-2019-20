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

	/*HR(const Person& person = Person("name1", "name2", 42), double salary = 800,
		Vector<Person*> potentialEmployees = Vector<Person*>(),
		Vector<const char*> knownBuzzwords = Vector<const char*>());*/

	void addPotentialEmployee(Person* potentialEmployee);
	void addBuzzword(const char* buzzword);
	void giveAdvice();

	virtual void work();

private:
	Vector<Person*> potentialEmployees;
	Vector<const char*> knownBuzzwords;
};

