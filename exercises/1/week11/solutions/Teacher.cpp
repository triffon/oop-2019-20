
Teacher::Teacher(string name, int age, double salary, string subject) : Employee(name, age, "teacher", salary) {
	this->subject = subject;
}

string Teacher::activity() {
	return "Teaching";
}


void Teacher::print() {
	Employee::print();
	cout << "Subject: " << subject << endl;
}