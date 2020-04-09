#include "StudentDynamic.h"
#include <iostream>
#include <fstream>

using namespace std;

void StudentDynamic::copy(const StudentDynamic& other)
{
	size_t nameLength = strlen(other.name);
	name = new char[nameLength + 1];
	strcpy_s(name, nameLength + 1, other.name);
	fn = other.fn;
}

StudentDynamic::StudentDynamic()
{
	this->name = nullptr;
	fn = -1;
}

StudentDynamic::StudentDynamic(const char* name, int fn)
{
	size_t nameLength = strlen(name);
	this->name = new char[nameLength + 1];
	strcpy_s(this->name, nameLength + 1, name);
	this->fn = fn;
}

StudentDynamic::StudentDynamic(const StudentDynamic& other)
{
	copy(other);
}

StudentDynamic::~StudentDynamic()
{
	delete[] name;
}

StudentDynamic& StudentDynamic::operator=(const StudentDynamic& other)
{
	if (this == &other) {
		return *this;
	}
	delete[] name;
	copy(other);
}

void StudentDynamic::serialize(ofstream& fileOut)
{
	size_t nameLength = strlen(name);
	fileOut << nameLength << endl << this->name << endl << fn << endl;
}

void StudentDynamic::deserialize(ifstream& fileIn)
{
	size_t nameLength;
	fileIn >> nameLength;
	delete[] name;
	name = new char[nameLength + 1];
	fileIn >> name;
	fileIn >> fn;
	name[nameLength] = 0;
}

void StudentDynamic::serializeBinary(ofstream& fileOut)
{
	size_t nameLength = strlen(name);
	fileOut.write((const char*)&nameLength, sizeof(size_t));
	fileOut.write((const char*)name, nameLength + 1);
	fileOut.write((const char*)&fn, sizeof(int));
}

void StudentDynamic::deserializeBinary(ifstream& fileIn)
{
	size_t nameLength;
	fileIn.read((char*)&nameLength, sizeof(size_t));
	name = new char[nameLength + 1];
	fileIn.read(name, nameLength + 1);
	fileIn.read((char*)&fn, sizeof(int));
}


