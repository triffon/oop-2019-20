#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string firstName, string lastName, int age);

	void write(ostream& out) const;

	int getAge() const;
protected:
	string firstName;
	string lastName;
	int age;
};

ostream& operator<< (ostream& out, Person& p);