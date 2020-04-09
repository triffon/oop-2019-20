#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

Student::Student()
{
	strcpy_s(name, 1, "");
	fn = -1;
}

Student::Student(const char* name, int fn)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->fn = fn;
}

void Student::serialize(ofstream& fileOut)
{
	fileOut << this->name << endl << fn << endl;
}

void Student::deserialize(ifstream& fileIn)
{
	fileIn >> this->name >> fn;
}

void Student::serializeBinary(ofstream& fileOut)
{
	fileOut.write((const char*)this, sizeof(Student));
}

void Student::deserializeBinary(ifstream& fileIn)
{
	fileIn.read((char*)this, sizeof(Student));
}


