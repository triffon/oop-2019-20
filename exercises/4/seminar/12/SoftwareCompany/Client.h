#pragma once

#include<iostream>

#include "Vector.h"
#include "Person.h"
#include "Project.h"

class Project;

class Client: public Person {
public:
	Client(const Person& p = Person("name1", "name2", 42), Vector<Project> projects = Vector<Project>(nullptr, 0));
	Client(string firstName, string lastName, int age, Vector<Project> projects = Vector<Project>(nullptr, 0));

	const string getName() const;

	void write(ostream& out) const;
private:
	Vector<Project> projects;
};

ostream& operator<<(ostream& out, const Client& c);