
class Student : virtual public Person {
private:
	string fn;
	int course;
	int group;

public:
	Student(string name = "Unknown", int age = 0, string fn = "Unknown", int course = 0, int group = 0);

	string activity();

	void print();
};


#include "Student.cpp"