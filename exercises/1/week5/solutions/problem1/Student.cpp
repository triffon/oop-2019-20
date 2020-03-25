#pragma once

#include "Student.h"
#include <iostream>
using namespace std;


void Student::copy(const Student &other)
{
	if (name != nullptr)
	{
		delete[] name;
	}

	int len = strlen(other.name);
	this->name = new char[len + 1];
	strcpy(this->name, other.name);

	this->reg_number = other.reg_number;
	this->hasSubject = other.hasSubject;
}

Student::Student(int reg_number, const char *name, bool has_subject)
{
	this->reg_number = reg_number;
	this->hasSubject = has_subject;

	if (name != nullptr)
	{
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}
	else
	{
		name = nullptr;
	}
}

Student::Student(const Student &other)
{
	copy(other);
}

Student& Student::operator=(const Student &other)
{
	// Avoiding
	// Student a;
	// a = a;
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

Student::~Student()
{
	delete[] name;
}


void Student::print()
{
	cout << "name: " << this->name << " reg number: " << this->reg_number << endl;
}
