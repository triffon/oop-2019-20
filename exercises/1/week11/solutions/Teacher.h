
class Teacher : public Employee {
private:
	string subject;
public:
	Teacher(string name = "Unknown", int age = 0, double salary = 0.0, string subject = "Unknown");

	string activity();

	void print();
};


#include "Teacher.cpp"