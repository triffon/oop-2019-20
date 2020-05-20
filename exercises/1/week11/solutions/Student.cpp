
Student::Student(string name, int age, string fn, int course, int group) : Person(name, age) {
	this->fn = fn;
	this->course = course;
	this->group = group;
}

string Student::activity() {
	return "Studying";
}


void Student::print() {
	Person::print();
	cout << "FN: " << fn << endl;
	cout << "Course: " << course << endl;
	cout << "Group: " << group << endl;
}
