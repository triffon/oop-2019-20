
class Employee : virtual public Person {
private:
	string occupation;
	double salary;

public:
	Employee(string name = "Unknown", int age = 0, string occupation = "Unknown", double salary = 0.0);

	string activity();

	void print();
};


#include "Employee.cpp"