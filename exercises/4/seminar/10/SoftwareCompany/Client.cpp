#include "Client.h"

Client::Client(Person& p, Vector<string> orders): Person(p), orders(orders) {}
Client::Client(string firstName, string lastName, int age, Vector<string> orders): Person(firstName, lastName, age), orders(orders) {}

void Client::write(ostream& out) const {
	Person::write(out);
	cout << "orders: ";
	for (int i = 0; i < orders.getSize(); ++i) {
		cout << orders[i] << " ";
	}
}

ostream& operator<<(ostream& out, const Client& c) {
	c.write(out);
	return out;
}
