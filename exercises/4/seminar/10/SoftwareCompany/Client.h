#pragma once

#include<iostream>

#include "Person.h"
#include "Vector.h"
class Client: public Person {
public:
	Client(Person& p, Vector<string> orders = Vector<string>(nullptr, 0));
	Client(string firstName, string lastName, int age, Vector<string> orders = Vector<string>(nullptr, 0));

	void write(ostream& out) const;
private:
	Vector<string> orders;
};

ostream& operator<<(ostream& out, const Client& c);