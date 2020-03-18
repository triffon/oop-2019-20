#include "SoftwareEnginner.hpp"

bool SoftwareEngineer::isValid() const
{
	if (strcmp(f_name, "") == 0 || f_grade == Grade::InvalidGrade)
	{
		return false;
	}

	return true;
}

Grade SoftwareEngineer::getGrade() const
{
	return f_grade;
}

int SoftwareEngineer::ceoCount() const
{
	return f_grade == Grade::CEO ? 1 : 0;
}

int SoftwareEngineer::ctoCount() const
{
	return f_grade == Grade::CTO ? 1 : 0;
}

void SoftwareEngineer::print() const
{
	std::cout << f_name << " ," << (int)f_grade << ", " << f_salary << std::endl;
}

SoftwareEngineer::SoftwareEngineer(const char* name, Grade grade, unsigned salary)
	: f_grade(grade), f_salary(salary)
{
	setName(name);
}

SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer& other)
	: SoftwareEngineer()
{
	if (this != &other)
	{
		copy(other);
	}
}

SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}

	return *this;
}

SoftwareEngineer::~SoftwareEngineer()
{
	del();
}

void SoftwareEngineer::del()
{
	delete[] f_name;
}

void SoftwareEngineer::copy(const SoftwareEngineer& other)
{
	setName(other.f_name);
	f_grade = other.f_grade;
	f_salary = other.f_salary;
}

void SoftwareEngineer::setName(const char* name)
{
	if (name == nullptr)
	{
		f_name = new char[1];
		strcpy(f_name, "");
		return;
	}

	f_name = new char[strlen(name) + 1];
	strcpy(f_name, name);
}
