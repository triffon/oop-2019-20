#pragma once
#pragma warning(disable: 4996)

#include <iostream>

class Student {
private:
	char m_name[51];
	char m_major[33];
	unsigned int m_facultyNumber;
	int m_group;

	void copy(const char* name, const char* major, unsigned int fn, int group);
	void setName(const char* name);
	void setFacultyNumber(const int facultyNumber);
	bool isValidMajor(const char* major);
public:
	Student();
	Student(const char* name, const char* major, unsigned int facultyNumber, int group);

	unsigned int getFacultyNumber() const;
	int getGroup() const;
	const char* getName() const;
	const char* getMajor() const;

	void setGroup(int group);
	void setMajor(const char* major);

	void printInformation() const;
	void readFromConsole();
};
