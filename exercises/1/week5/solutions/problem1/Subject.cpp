#include "Subject.h"
#include "Student.h"
#include <iostream>

University * Subject::uni = nullptr;

void Subject::setUni(University *uni)
{
	Subject::uni = uni;
}

Subject::Subject()
{
	if(uni != nullptr)
		regNumArr = new int[uni->count()];
}



Subject::~Subject()
{
	if (regNumArr != nullptr)
	{
		delete[] regNumArr;
	}
}


void Subject::addStudentNumber(int reg_num)
{
	if (reg_num < uni->count() && size < uni->count())
	{
		regNumArr[size++] = reg_num;
		(*uni)[reg_num].hasSubject = true;

	}
}

void Subject::printStudentsWhithoutSubject()
{
	std::cout << "students without subjects: \n";
	for (size_t i = 0; i < uni->count(); i++)
	{
		if(!(*uni)[i].hasSubject)
			(*uni)[i].print();
	}
}

Student& Subject::operator[](int i)
{
	return (*uni)[regNumArr[i]];
}
