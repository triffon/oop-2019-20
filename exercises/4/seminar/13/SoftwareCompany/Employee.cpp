#include "Employee.h"

Employee::Employee(const Person& p, double salary, string email): Person(p), salary(salary), email(email) {
	if (email.compare(string("")) != 0) {
		return;
	}

	this->email = firstName + "." + lastName + "@firma.bg";
}

void Employee::work() {
	cout << "work\n";
}

string Employee::getName() const {
	return firstName;
}

void Employee::write(ostream& out) const {
	Person::write(out);
	out << "email: " << email<< endl;
}

ostream& operator<<(ostream& out, const Employee& e) {
	e.write(out);
	return out;
}
