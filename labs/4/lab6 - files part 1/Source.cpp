#include "Student.h"
#include "StudentDynamic.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

void assertEqual(const Student& s1, const Student& s2) {
	assert(strcmp(s1.getName(), s2.getName()) == 0);
	assert(s1.getFn() == s2.getFn());
}

void assertEqual(const StudentDynamic& s1, const StudentDynamic& s2) {
	assert(strcmp(s1.getName(), s2.getName()) == 0);
	assert(s1.getFn() == s2.getFn());
}

void testStudents(bool binary = false) {
	Student s1("Pe6o", 1002);
	Student s2("Pe6o2", 1000);

	const char* fileName = binary ? "students.dat" : "students.txt";
	ofstream fileOut;

	if (binary) {
		fileOut.open(fileName, ios::binary);
		s1.serializeBinary(fileOut);
		s2.serializeBinary(fileOut);
	}
	else {
		fileOut.open(fileName);
		s1.serialize(fileOut);
		s2.serialize(fileOut);
	}
	fileOut.close();

	ifstream fileIn;


	Student s3, s4;
	if (binary) {
		fileIn.open(fileName, ios::binary);
		s3.deserializeBinary(fileIn);
		s4.deserializeBinary(fileIn);
	}
	else {
		fileIn.open(fileName);
		s3.deserialize(fileIn);
		s4.deserialize(fileIn);
	}
	assertEqual(s1, s3);
	assertEqual(s2, s4);
	s3.print();
	s4.print();
}

void testDynamicStudents(bool binary = false) {
	StudentDynamic s1("Pe6o", 1002);
	StudentDynamic s2("Pe6o2", 1000);

	const char* fileName = binary ? "dynamicStudents.dat" : "dynamicStudents.txt";
	ofstream fileOut;


	if (binary) {
		fileOut.open(fileName, ios::binary);
		s1.serializeBinary(fileOut);
		s2.serializeBinary(fileOut);
	}
	else {
		fileOut.open(fileName);
		s1.serialize(fileOut);
		s2.serialize(fileOut);
	}
	fileOut.close();


	ifstream fileIn;
	StudentDynamic s3, s4;
	if (binary) {
		fileIn.open(fileName, ios::binary);
		s3.deserializeBinary(fileIn);
		s4.deserializeBinary(fileIn);
	}
	else {
		fileIn.open(fileName, ios::binary);
		s3.deserialize(fileIn);
		s4.deserialize(fileIn);
	}
	assertEqual(s1, s3);
	assertEqual(s2, s4);
	s3.print();
	s4.print();
}

int main() {

	testStudents(true);
	testStudents();
	testDynamicStudents(true);
	testDynamicStudents();

}