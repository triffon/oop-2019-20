#pragma once
#include "Employee.h"
#include "Vector.h"
class Programmer: public Employee {
public:
	Programmer(const Employee& employee, const char* rubberDuckName = "Quackers");

private:
	const char* rubberDuckName;
};
