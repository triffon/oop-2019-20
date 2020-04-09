#include <iostream>
#include "Money.h"
using namespace std;

void Money::normalize()
{
	dollars += cents / 100;
	cents %= 100;
	if (cents < 0) {
		cents = -cents;
	}
}

void Money::increment()
{
	if (dollars < 0)
		--cents;
	else
		++cents;
	normalize();
}

Money::Money() {
	dollars = 0;
	cents = 0;
}

Money::Money(int cents)
{
	dollars = 0;
	this->cents = cents;
	normalize();
}

Money::Money(int dollars, int cents) {
	this->dollars = dollars;
	this->cents = cents;
	normalize();
}

int Money::asCents() const
{
	if (dollars >= 0) {
		return dollars * 100 + cents;
	}
	return dollars * 100 - cents;
}

Money Money::operator-(const Money& other)
{
	Money result(asCents() - other.asCents());
	return result;
}

Money Money::operator+(const Money& other)
{
	Money result(asCents() + other.asCents());
	return result;
}

Money& Money::operator+=(const Money& other)
{
	dollars += other.dollars;
	cents += other.cents;
	normalize();
	return *this;
}

Money& Money::operator-=(const Money& other)
{
	cents = asCents() - other.asCents();
	dollars = 0;
	normalize();
	return *this;
}

bool Money::operator>(const Money& other)
{
	return asCents() > other.asCents();
}

bool Money::operator==(const Money& other)
{
	return asCents() == other.asCents();
}

bool Money::operator<(const Money& other)
{
	return !(*this > other) && !(*this == other);
}

bool Money::operator>=(const Money& other)
{
	return !(*this < other);
}

bool Money::operator<=(const Money& other)
{
	return !(*this > other);
}

bool Money::operator!=(const Money& other)
{
	return !(*this == other);
}

Money Money::operator++(int)
{
	Money result(*this);
	increment();
	return result;
}



Money& Money::operator++()
{
	increment();
	return *this;
}

void Money::print() {
	cout << dollars << "." << cents << "$" << endl;
}