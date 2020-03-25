#pragma once
#pragma warning(disable:4996)
#include <string.h>
#include <iostream>
#include "Grade.h"

class SoftwareEngineer
{
public:
	bool isValid() const;
	Grade getGrade() const;
	int ceoCount() const;
	int ctoCount() const;
	void print() const;

public:
	SoftwareEngineer(const char* name = "", Grade grade = DefaultGrade, unsigned salary = 0);
	SoftwareEngineer(const SoftwareEngineer& other);
	SoftwareEngineer& operator=(const SoftwareEngineer& other);
	~SoftwareEngineer();

private:
	void del();
	void copy(const SoftwareEngineer& other);
	void setName(const char* name);

private:
	char* f_name;
	Grade f_grade;
	unsigned f_salary;

	static const Grade DefaultGrade = Grade::InvalidGrade;
};