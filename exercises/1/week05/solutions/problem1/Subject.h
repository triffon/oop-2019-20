#pragma once
#include "University.h"


/*
//what static does
class A {
	static int b;

	int a = 0;

public:
	static void setB(int _b)
	{
		// a+=2 gives Error
		b = _b;
	}
	void addOne()
	{
		b += 1;
	}
	void print();
	{
		cout << b << endl;
	}
};
int A::b = 0;
//
int main(){
	A::setB(2); // valid
	A a1;
	A a2;
	a1.setB(2); // valid
	a1.addOne();
	a2.addOne();

	a1.print(); // prints 4
	a2.print(); //prints 4
	return 0;
}
*/


class Subject
{
	static University *uni;

	int *regNumArr = nullptr;
	int size = 0;
public:
	static void setUni(University *uni);
	Subject();
	~Subject();

	void addStudentNumber(int reg_num);
	
	static void printStudentsWhithoutSubject();
	
	Student& operator[](int i);

	//to Be implemented
	//Subject(const Subject &other)
	//Subject& operator=(const Subject &other)

};

