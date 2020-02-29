#include "Student.hpp"

// Sets default values for all of the object fields.
Student::Student()
{
	copy("", "", 0, 0);
}

// Sets all values for the object with the parameters.
Student::Student(const char* name, const char* major, unsigned int facultyNumber, int group)
{
	copy(name, major, facultyNumber, group);
}

// Copies the parameters to the fields of the objects and does validation through the setters.
void Student::copy(const char* name, const char* major, unsigned int fn, int group)
{
	setFacultyNumber(fn);
	setGroup(group);
	setName(name);
	setMajor(major);
}

// Private setter. Sets a new value for the 'facultyNumber'. Has validation, if the number is not 5 digits, sets 0.
void Student::setFacultyNumber(const int facultyNumber)
{
	m_facultyNumber = (facultyNumber > 10000 && facultyNumber <= 99999) ? facultyNumber : 0;
}

// Public setter. Sets a new value for the 'group'. Has validation, if the number is not in the range [1,8], sets 0.
void Student::setGroup(const int group)
{
	m_group = (group >= 1 && group <= 8) ? group : 0;
}

// Private setter. Sets a new value for the 'name'. 
void Student::setName(const char* name)
{
	strcpy(m_name, name);
}

// Public setter. Sets a new value for 'major'. Has validation, if the major is not valid, sets empty string.
void Student::setMajor(const char* major)
{
	if (isValidMajor(major))
	{
		strcpy(m_major, major);
	}
	else
	{
		strcpy(m_major, "");
	}
}

// Getters
unsigned int Student::getFacultyNumber() const
{
	return m_facultyNumber;
}

int Student::getGroup() const
{
	return m_group;
}

const char* Student::getName() const
{
	return m_name;
}

const char* Student::getMajor() const
{
	return m_major;
}
// !Getters

// Checks if the parameter is one of the 5 valid majors.
bool Student::isValidMajor(const char* major)
{
	const size_t size = 5;
	const char* validMajors[size] = { "Informatics", "Computer Science", "Software Engineering", "Mathematics and Informatics", "Mathematics" };

	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(major, validMajors[i]) == 0)
		{
			return true;
		}
	}

	return false;
}

// Prints information about the student to the console.
void Student::printInformation() const
{
	std::cout << "Student \'" << m_name << "\', FN " << m_facultyNumber << ", \'" << m_major << "\', group " << m_group << std::endl;
}

// Reads values for the student from the console.
void Student::readFromConsole()
{
	char name[200];
	char major[50];
	unsigned int facultyNumber;
	int group;

	std::cout << "Name: ";
	std::cin >> name;

	std::cout << "Major: ";
	std::cin >> major;

	std::cout << "Faculty number: ";
	std::cin >> facultyNumber;

	std::cout << "Group: ";
	std::cin >> group;

	copy(name, major, facultyNumber, group);
}