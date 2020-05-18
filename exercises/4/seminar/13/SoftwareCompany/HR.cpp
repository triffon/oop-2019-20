#include <cstdlib>
#include "HR.h"

HR::HR(const Employee& employee, Vector<Person*> potentialEmployees, Vector<const char*> knownBuzzwords):
	Employee(employee), potentialEmployees(potentialEmployees), knownBuzzwords(knownBuzzwords) {}

/*HR::HR(const Person& person, double salary, Vector<Person*> potentialEmployees, 
	Vector<const char*> knownBuzzwords) : Employee(person, salary), 
	potentialEmployees(potentialEmployees), knownBuzzwords(knownBuzzwords) {}*/

void HR::addPotentialEmployee(Person* potentialEmployee) {
	potentialEmployees.append(potentialEmployee);
}

void HR::addBuzzword(const char* buzzword) {
	knownBuzzwords.append(buzzword);
}

void HR::giveAdvice() {
	cout<< "I think we should " << knownBuzzwords[rand() % knownBuzzwords.getSize()]<< endl;
}

void HR::work() {
	giveAdvice();
}
