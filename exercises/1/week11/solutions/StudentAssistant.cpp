
StudentAssistant::StudentAssistant(string name, int age, double salary, string subject, string fn, int course, int group, int groupsCount) : 
Student(name, age, fn, course, group), Teacher(name, age, salary, subject), Person(name, age) {
	this->groupsCount = groupsCount;
}

string StudentAssistant::activity() {

	return Student::activity() + Teacher::activity();

}

void StudentAssistant::print() {
	Teacher::print();
	Student::print();
}