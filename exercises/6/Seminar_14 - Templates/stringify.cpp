#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

class Student
{
	std::string f_name;
	int f_fn;
public:
	Student(std::string name, int fn) : f_name(name), f_fn(fn) {}

	friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	return out << student.f_name << " " << student.f_fn << std::endl;
}

template <typename T>
std::string stringify(const T& object)
{
	std::ostringstream out;
	out << object;

	return out.str();
}

template <>
std::string stringify<double>(const double& object)
{
	std::ostringstream out;
	out << std::setprecision(10) << object;

	return out.str();
}

template <>
std::string stringify<float>(const float& object)
{
	std::ostringstream out;
	out << std::setprecision(10) << object;

	return out.str();
}

template <>
std::string stringify<bool>(const bool& object)
{
	std::ostringstream out;
	out << std::boolalpha << object;

	return out.str();
}


int main()
{
	Student stud("Yasi", 99999);
	std::cout << stringify(stud) << std::endl;
	std::cout << stringify(true) << std::endl;
	std::cout << stringify(5) << std::endl;
	std::cout << stringify("Text text") << std::endl;
	std::cout << stringify(5555555.124141231231211213113);
}

