#include <iostream>
#include "MotherShip.h"
#include "Bomber.h"
#include "Interceptor.h"
#include "DropShip.h"
using namespace std;

class A {
public:
	virtual void func() = 0;

	//винаги трябва да е виртуален!!!
	virtual ~A()
	{
		cout << "~A()" << endl;
	}
};

class B : public A{
public:
	virtual void func() {
		cout << "B" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
};
class C : public A {
public:
	virtual void func() {
		cout << "C" << endl;
	}

	~C()
	{
		cout << "~C()" << endl;
	}
};


int main()
{
	A *a[2];

	a[0] = new B();
	a[1] = new C();

	for (int i = 0; i < 2; i++)
	{
		a[i]->func();
	}

	for (int i = 0; i < 2; i++)
	{
		delete a[i];
	}


	//
	//Bomber b1;
	//Bomber b2(b1);
	//b1 = b2;


	MotherShip & msh = MotherShip::getIntsance();

	Bomber *b = msh.createBomber();

	b->attack();
	b->printType();
	b->printInfo();


	DropShip *d = msh.createDropShip();
	d->attack();
	d->printType();
	d->printInfo();

	Interceptor *i = msh.createInterceptor();
	i->attack();
	i->printType();
	i->printInfo();


	msh.printStarshipInfo();


	return 0;
}