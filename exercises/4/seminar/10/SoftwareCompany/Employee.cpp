#include "Employee.h"

Employee::Employee(const Person& p, string email): Person(p), email(email) {
	if (email.compare(string("")) != 0) {
		return;
	}

	this->email = firstName + "." + lastName + "@firma.bg";
}

void Employee::write(ostream& out) const {
	Person::write(out);
	out << "email: " << email<< endl;
}

ostream& operator<<(ostream& out, const Employee& e) {
	e.write(out);
	return out;
}
