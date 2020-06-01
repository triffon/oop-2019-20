#include "Programmer.h"

Programmer::Programmer(const Person& person, double salary, const char* rubberDuckName) :
	Employee(person, salary), rubberDuckName(rubberDuckName) {}

void Programmer::work() {
	cout << "talking to " << rubberDuckName << " about a bug i have to fix\n";
}
