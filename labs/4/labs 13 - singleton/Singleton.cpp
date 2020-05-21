#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::_instance = nullptr;

Singleton* Singleton::getInstance() {
	if (!_instance) {
		_instance = new Singleton();
	}

	return _instance;
}

void Singleton::setData(int data)
{
	_data = data;
}

int Singleton::getData()
{
	return _data;
}

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

void Singleton::destroy()
{
	delete _instance;
	_instance = nullptr;
}

void Singleton::print() {
	cout << "bla bla" << endl;
}
