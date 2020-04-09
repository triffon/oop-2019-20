#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class StudentDynamic
{
	char* name;
	int fn;

	void copy(const StudentDynamic& other);
public:
	StudentDynamic();
	StudentDynamic(const char* name, int fn);
	StudentDynamic(const StudentDynamic& other);
	~StudentDynamic();
	StudentDynamic& operator=(const StudentDynamic& other);

	void print() {
		cout << name << endl << fn << endl;
	}

	void serialize(ofstream& fileOut);
	void deserialize(ifstream& fileIn);

	void serializeBinary(ofstream& fileOut);
	void deserializeBinary(ifstream& fileIn);

	const char* getName() const { return name; }
	int getFn() const { return fn; }
};

