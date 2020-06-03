#pragma once
#include "Employee.h"
#include "Vector.h"
class Programmer: public Employee {
public:
	Programmer(const Person& person = Person("name1", "name2", 42), 
		double salary = 800, const char* rubberDuckName = "Quackers");

	virtual void work();
private:
	const char* rubberDuckName;
};
