#pragma once
class Student;

class University
{
	Student **students = nullptr;
	int size = 0;
	int capacity = 0;

	void erase();

	void copy(const University &other);
public:
	University();

	University(const University &other);

	University& operator=(const University &other);

	~University();

	void addStudent(const char *name);

	Student& operator[](int i);

	int count();

	University operator+(const University &other);

};
