#pragma once

class Person {

	private:
		char* name;
		int age;
		bool hasDrivingLicense;

		void copy(const Person& p);

		void erase();
	
	public:

		Person();

		Person(const char* name, const int age, const bool hasDrivingLicense);

		Person(const Person& p);

		Person& operator=(const Person& other);

		~Person();

		bool operator==(const Person& p);

		const char* getName() const;

		int getAge() const;

		bool getDrivingLicense() const;

		void setName(const char* name);

		void setAge(const int age);

		void setDrivingLicense(const bool hasDrivingLicense);

		void print();
};

#include "person.cpp"
