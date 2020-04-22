#include<iostream>
using namespace std;

class Person {

private:
	int age;//the class that inherits Person cant access age,
protected://the class that inherits Person could access salary, but only in the bodies of its methods
	//Mechanic m; m.salary is invalid
	int salary;
public:
	Person(int _age):age(_age)
	{}

	void printAge()
	{
		cout << age << endl;
	}
	
	//virtual void printJob() = 0; - pure virtual function (we cant make an instance of that class)
	virtual void printJob() {
		cout << "Unemployed" << endl;
	};
};

				//could be ": private Person", ": protected Person", ": public Person"
class Mechanic : public Person
{
public:
	Mechanic() : Person(34)
	{
		//age = 12; invalid
		salary = 100;
	}
	virtual void printJob()
	{
		cout << "Mechanic" << endl;
	}
};

class CarMechanic : public Mechanic
{

};

class Gardener : public Person
{
public:
	Gardener() : Person(12)
	{

	}

	virtual void printJob()
	{
		cout << "Gardner" << endl;
	}
};


class Workers
{
	Person *workers[3];
	int counter = 0;
	const int max_size = 3;

public:
	void addWorker(Person *p)
	{
		if (counter < max_size - 1)
		{
			workers[counter++] = p;
			p->printJob();
		}
	}

	~Workers()
	{
		for (size_t i = 0; i < max_size; i++)
		{
			delete workers[i];
		}
	}
};

int main()
{
	//Person p;
	Mechanic m;
	m.printAge();

	Workers w;
	w.addWorker(new Mechanic());
	w.addWorker(new Gardener());
	return 0;
}