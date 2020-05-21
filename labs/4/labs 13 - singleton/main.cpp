#include <iostream>
#include "Singleton.h"

using namespace std;


class DumbClass {
public:
	static int x;

	DumbClass() {
		x++;
	}


	~DumbClass() {
		x--;
	}

	static int getX() {
		return x;
	}
};

int DumbClass::x = 0;


void changeValue() {
	Singleton::getInstance()->setData(44);
}


void printAddress2() {
	cout << &(*Singleton::getInstance()) << endl;
}

int main() {
	/*DumbClass* ptr = new DumbClass;
	delete ptr;
	DumbClass x, y, z;
	cout << DumbClass::getX();*/

	Singleton * inst = Singleton::getInstance();

	
	inst->setData(10);

	cout << inst->getData()<<endl;

	//Singleton x = *inst; ne raboti

	changeValue();

	printAddress2();

	cout << inst->getData() << endl;

	Singleton::destroy();

	cout << &(*Singleton::getInstance()) << endl;

	Singleton::print();

	cin.get();
}