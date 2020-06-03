#include "Person.h"

Person::Person(string firstName, string lastName, int age): firstName(firstName), lastName(lastName), age(age) {}

void Person::write(ostream& out) const {
	out << firstName << " " << lastName << " " << age << endl;
}

int Person::getAge() const {
	return age;
}

ostream& operator<<(ostream& out, Person& p) {
	p.write(out);
	return out;
}
