#include <string>
#include "String.h"

void String::initializeFromCharArray(const char* data)
{
	if (data == nullptr)
	{
		data = "";
	}

	f_size = strlen(data);
	f_data = new char[f_size];

	for (size_t i = 0; i < f_size; i++)
	{
		f_data[i] = data[i];
	}
}

void String::copy(const String& other)
{
	f_size = other.f_size;
	f_data = new char[f_size];
	for (size_t i = 0; i < f_size; i++)
	{
		f_data[i] = other.f_data[i];
	}
}

String::String(const char* data)
{
	initializeFromCharArray(data);
}

String::String(const char c)
{
	initializeFromCharArray(&c);
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] f_data;
		copy(other);
	}

	return *this;
}

String::~String()
{
	delete[] f_data;
}

String& String::operator+=(const String& other)
{
	size_t newSize = f_size + other.f_size;
	char* newData = new char[newSize];

	for (size_t i = 0; i < f_size; i++)
	{
		newData[i] = f_data[i];
	}

	for (size_t i = 0; i < other.f_size; i++)
	{
		newData[i + f_size] = other.f_data[i];
	}

	delete[] f_data;
	f_data = newData;
	f_size = newSize;

	return *this;
}

String& String::operator+=(const char* data)
{
	return *this += String(data);
}

String& String::operator+=(const char c)
{
	return *this += String(c);
}

const char* String::ToDynamicCharArray() const
{
	char* convertedData = new char[f_size + 1];

	for (size_t i = 0; i < f_size; i++)
	{
		convertedData[i] = f_data[i];
	}
	convertedData[f_size] = 0;

	return convertedData;
}

String operator+(const String& first, const String& second)
{
	String result = first;
	result += second;
	return result;
}

String operator+(const String& first, const char* second)
{
	return first + String(second);
}

String operator+(const char* first, const String& second)
{
	return String(first) + second;
}

String operator+(const String& first, const char second)
{
	return first + String(second);
}

String operator+(const char first, const String& second)
{
	return String(first) + second;
}

bool operator==(const String& first, const String& second)
{
	if (first.f_size != second.f_size)
	{
		return false;
	}

	for (size_t i = 0; i < first.f_size; i++)
	{
		if (first.f_data[i] != second.f_data[i])
		{
			return false;
		}
	}

	return true;
}

bool operator==(const String& first, const char* second)
{
	return first == String(second);
}

bool operator==(const char* first, const String& second)
{
	return String(first) == second;
}

bool operator==(const String& first, const char second)
{
	return first == String(second);
}

bool operator==(const char first, const String& second)
{
	return String(first) == second;
}

bool operator!=(const String& first, const String& second)
{
	return !(first == second);
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
	for (size_t i = 0; i < string.f_size; i++)
	{
		out << string.f_data[i];
	}

	return out;
}

std::istream& operator>>(std::istream& in, String& string)
{
	const size_t BUFFER_SIZE = 1000;
	char buffer[BUFFER_SIZE];
	in >> buffer;

	String newString = String(buffer);
	string = newString;

	return in;
}
