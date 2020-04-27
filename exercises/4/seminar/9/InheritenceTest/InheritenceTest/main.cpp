// InheritenceTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Utility.h"
using namespace std;

class Person {
protected:
	const char* name;
	int age;

public:
	Person(const char* name = nullptr, int age = 30) : name(name), age(age) {}
};

class Employee : public Person {
public:
	double salary;

	Employee(const char* name, int age, double salary) : Person(name, age), salary(salary) {}
};

class Client : public Person {
public:
	char* order;

	Client(): order(nullptr) {}

	void setOrder(const char* newOrder) {
		order = new char[Utility::strlen(newOrder) + 1];
		Utility::strcpy(order, newOrder);
	}

	Client(Client& other) = delete;
	Client& operator=(Client& other) = delete;

	~Client() {
		delete[] order;
	}
};

class HR : public Employee {
public:
	char* email; //"John Smith"

	HR(const char* name, int age, double salary) : Employee(name, age, salary) {
		email = new char[Utility::strlen(name) + Utility::strlen("@gmail.com") + 1];
		// constr
	}

	void print() {

		cout << name << endl;
	}

	~HR() {
		delete[] email;
	}
};

int main() {

	Person p("georgi", 25);

	Client c;
	c.setOrder("1 programa molq");
	cout << c.order<< endl;
}