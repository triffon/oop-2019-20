#pragma once
#include <fstream>

class String
{
private:
	char* f_data;
	size_t f_size;

private:
	void initializeFromCharArray(const char* data);
	void copy(const String& other);

public:
	String(const char* data = "");
	String(const char c);
	String(const String& other);
	String& operator=(const String& other);
	~String();

public:
	String& operator+=(const String& other);
	String& operator+=(const char* data);
	String& operator+=(const char c);

public:
	friend String operator+(const String& first, const String& second);
	friend String operator+(const String& first, const char* second);
	friend String operator+(const char* first, const String& second);
	friend String operator+(const String& first, const char second);
	friend String operator+(const char first, const String& second);

	friend bool operator==(const String& first, const String& second);
	friend bool operator==(const String& first, const char* second);
	friend bool operator==(const char* first, const String& second);
	friend bool operator==(const String& first, const char second);
	friend bool operator==(const char first, const String& second);

	friend bool operator!=(const String& first, const String& second);

	friend bool operator<(const String& first, const String& second);
	friend bool operator<(const String& first, const char* second);
	friend bool operator<(const char* first, const String& second);
	friend bool operator<(const String& first, const char second);
	friend bool operator<(const char first, const String& second);

	friend std::ostream& operator<<(std::ostream& out, const String& string);
	friend std::istream& operator>>(std::istream& in, String& string);

	const char* ToDynamicCharArray() const;
public:
};

