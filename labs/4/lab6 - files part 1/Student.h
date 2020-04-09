#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	char name[50];
	int fn;
public:
	Student();
	Student(const char* name, int fn);

	void serialize(ofstream& fileOut);
	void deserialize(ifstream& fileIn);

	void serializeBinary(ofstream& fileOut);
	void deserializeBinary(ifstream& fileIn);

	void print() {
		cout << name << endl << fn << endl;
	}

	const char* getName() const { return name; }
	int getFn() const { return fn; }
};

