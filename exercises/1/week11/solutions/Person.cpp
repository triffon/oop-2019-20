
Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}

void Person::print() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}
