// week5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Student.h"
#include "University.h"
#include "Subject.h"

int main()
{
	//Student s(0, "Pesho Pyrvi");
	//Student s1;
	//s1 = s;
	//s1.print();

	University u1;
	u1.addStudent("Pesho Pyrvi");
	u1.addStudent("Pesho Vtori");
	u1.addStudent("Pesho Treti");

	University u2;
	u2.addStudent("Penka Pyrva");
	u2.addStudent("Penka Vtora");
	u2.addStudent("Penka Treta");

	University u = u1 + u2;
	for (size_t i = 0; i < u.count(); i++)
	{
		u[i].print();
	}

	Subject::setUni(&u);

	Subject calculus;
	calculus.addStudentNumber(0);
	calculus.addStudentNumber(1);

	calculus[0].print();

	Subject linAlgebra;
	linAlgebra.addStudentNumber(2);
	linAlgebra.addStudentNumber(3);

	linAlgebra[1].print();

	Subject::printStudentsWhithoutSubject();

	return 0;
}