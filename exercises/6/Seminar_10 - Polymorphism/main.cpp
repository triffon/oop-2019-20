#include <iostream>


class A
{
public:
	A()
	{
		std::cout << "Constructor A" << std::endl;
	}
	virtual void function()
	{
		std::cout << "Class A function()" << std::endl;
	}

	virtual ~A()
	{

		std::cout << "Destructor A" << std::endl;
	}
};

class B : public A
{
	char* c;
public:
	B()
	{
		c = new char[ 1000 ];
		std::cout << "Constructor B" << std::endl;
	}
	void function()
	{
		std::cout << "Class B function()" << std::endl;
	}

	~B()
	{
		delete[] c;
		std::cout << "Destructor B" << std::endl;
	}

};


int main()
{
	A* pA = new A;
	pA->function();
	delete pA;

	std::cout << "-------------" << std::endl;

	B* pB = new B;
	pB->function();
	delete pB;

	std::cout << "-------------" << std::endl;
	A* ptrAB = new B;
	ptrAB->function();
	delete ptrAB;

	return 0;
}