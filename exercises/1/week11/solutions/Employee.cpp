
Employee::Employee(string name, int age, string occupation, double salary) : Person(name, age) {
	this->occupation = occupation;
	this->salary = salary;
}

string Employee::activity() {
	return "Working";
}


void Employee::print() {
	Person::print();
	cout << "Occupation: " << occupation << endl;
	cout << "Salary: " << salary << endl;
}
