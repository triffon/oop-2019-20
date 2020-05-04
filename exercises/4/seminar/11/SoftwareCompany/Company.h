#pragma once

#include "Employee.h"
#include "Project.h"

class Company {
public:
	static Company sharedInstance;
private:
	Company();

	Vector<Employee> employees;
	Vector<Project> projects;
};

