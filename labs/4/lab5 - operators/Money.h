#pragma once

class Money {
	int dollars;
	int cents;
	void normalize();
	void increment();
public:
	Money();
	Money(int cents);
	Money(int dollars, int cents);

	int asCents() const;

	Money operator-(const Money& other);
	Money operator+(const Money& other);

	Money& operator+=(const Money& other);
	Money& operator-=(const Money& other);

	bool operator>(const Money& other);
	bool operator==(const Money& other);
	bool operator<(const Money& other);

	bool operator>=(const Money& other);
	bool operator<=(const Money& other);
	bool operator!=(const Money& other);

	Money operator++(int); // a++
	Money& operator++(); //++a

	void print();
};