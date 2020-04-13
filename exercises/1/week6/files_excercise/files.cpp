#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Entry
{
	int a = 1;
	int b = 2;
	char c[4];
};

class Employees
{
	struct Employee {
		char name[128];
		char occupation[128];
		double salary;
	};
	fstream f;

public:
	Employees()
	{
		
	}

	void addEmployee(char *name, char *occupation, double salary)
	{
		Employee e;
		strcpy(e.name, name);
		strcpy(e.occupation, occupation);
		e.salary;

		//ios::app (append) used so we could write at the end of the file
		f.open("employees.bin", ios::out | ios::app);

		f.write((char*)(&e), sizeof(e));

		f.close();
	}

};



int main()
{
	fstream f;

	f.open("testFile.txt", ios::in);//ios::out

	char a[3];
	a[2] = '\0';
	while (f.read(a, 2))
	{
		cout << a << endl;
	}

	//f.write(a, 2);

	f.close();

	f.open("binFile.bin", ios::out | ios::binary);
	Entry e;
	e.a = 10;
	e.b = 15;
	strcpy(e.c, "abc");
	
	//(char*)(&e) turns (*Entry) to (char*)
	f.write((char*)(&e), sizeof(e));
	f.close();

	f.open("binFile.bin", ios::in | ios::binary);

	Entry e2;
	strcpy(e2.c, "123");
	cout << "before read: "<< e2.a << " " << e2.b << " " <<e2.c << endl;
	f.read((char*)(&e2), sizeof(e2));
	cout << "after read: " << e2.a << " " << e2.b << " " << e2.c << endl;

	f.close();

	return 0;
}