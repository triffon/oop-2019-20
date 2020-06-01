#include "Project.h"
#include "Client.h"

Client::Client(const Person& p, Vector<Project> projects): Person(p), projects(projects) {}
Client::Client(string firstName, string lastName, int age, Vector<Project> projects): Person(firstName, lastName, age), projects(projects) {}

const string Client::getName() const {
	return firstName;
}

void Client::write(ostream& out) const {
	Person::write(out);
	cout << "orders: ";
	for (int i = 0; i < projects.getSize(); ++i) {
		cout << projects[i].getName() << " ";
	}
}

ostream& operator<<(ostream& out, const Client& c) {
	c.write(out);
	return out;
}
