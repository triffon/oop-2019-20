#pragma once
#include "University.h"
#include "Student.h"


University::University() {
}

University::University(const University &other)
{
	copy(other);
}

University& University::operator=(const University &other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

University::~University()
{
	erase();
}


void University::erase()
{
	if (students == nullptr)
		return;

	for (int i = 0; i < size; i++)
	{
		delete students[i];
	}
	delete[] students;
}

void University::copy(const University &other)
{
	erase();
	if (other.capacity != 0)
	{
		students = new Student*[other.capacity];
		for (int i = 0; i < other.size; i++)
		{
			students[i] = new Student(*other.students[i]);
		}
	}

	size = other.size;
	capacity = other.capacity;

}

void University::addStudent(const char *name)
{
	if (size == capacity)
	{
		Student **old = students;
		capacity = size * 2 + 1;
		students = new Student*[capacity];
		for (size_t i = 0; i < size; i++)
		{
			students[i] = old[i];
		}
	}
	students[size] = new Student(size, name);
	size++;
}

Student& University::operator[](int i)
{
	return *students[i];
}

int University::count()
{
	return size;
}

University University::operator+(const University &other)
{
	University u;
	int new_size = size + other.size;

	u.capacity = new_size;
	u.students = new Student*[new_size];
	
	int cnt = 0;
	for (size_t i = 0; i < size; i++)
	{
		u.students[cnt] = new Student(cnt, students[i]->name);
		cnt++;
	}
	for (size_t i = 0; i < other.size; i++)
	{
		u.students[cnt] = new Student(cnt, other.students[i]->name);
		cnt++;
	}

	u.size = new_size;

	return u;
}