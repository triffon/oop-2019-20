
class Person {
private:
	string name;
	int age;

public:
	Person(string name = "Unknown", int age = 0);

	virtual string activity() = 0;

	virtual void print();
};


#include "Person.cpp"