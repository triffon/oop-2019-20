#pragma once

#include <cstring>
#include <iostream>
#include "University.h"

class Student
{
	char *name = nullptr;
	int reg_number = -1;

	void copy(const Student &other);

public:
	bool hasSubject = false;

	Student(int reg_number = -1, const char *name = nullptr, bool has_subject = false);

	Student(const Student &other);

	Student& operator=(const Student &other);

	~Student();


	void print();

	// !!!!!
	// now University can access Student's private memebers
	friend class University;
};
