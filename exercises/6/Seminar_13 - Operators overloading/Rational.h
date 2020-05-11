#pragma once
#include<iostream>

class Rational {


	int64_t numerator;
	int64_t denominator;

private:

	int64_t gcd(int64_t, int64_t);

public:

	//can be used as transformer (implicit conversions)  
	//from long long to Rational or as a default constructor
	Rational(int64_t = 0, int64_t = 1);
	//the compiler's generated op= is good enough for us
	Rational& operator=(const Rational&) = default;

public : //some methods for better class usage

	void simplify();
	Rational simplified() const;

public: 

	//assignment operators 
	Rational& operator+=( const Rational& );
	Rational& operator-=( const Rational& );
	Rational& operator*=( const Rational& );
	Rational& operator/=( const Rational& );

	//comparison operators :

	//operator== is not a method !
	//it is a friend function
	friend bool operator==( const Rational& lhs, const Rational& rhs );
	friend bool operator<( const Rational& lhs, const Rational& rhs );
	//or could be member as well :
	/*
	bool operator<(const Rational& rhs) const{

	Rational l = this->simplified();
	Rational r = rhs.simplified();

	(l.numerator*r.denominator < l.denominator*r.numerator) ? true : false;
	}
	*/

	//input - output operators 
	friend std::ostream& operator<<( std::ostream&, const Rational& );
	friend std::istream& operator>>( std::istream&, Rational& );


	//the non-member functions operator<<, operator>>
	//will have access to Rational's private members
	
	//type convert operators

	//operator double() const;
	//operator float() const;
	//double asDouble() const;

	//cast operators
	
	//C++ 11 way of creating predictable operator bool
	explicit operator bool() const; // this must be explicit!!!
	bool operator!() const;

	//increment	- decrement operators

	//add and take
	
	Rational& operator++(); // <-- prefix ++r1
	const Rational operator++( int ); // <-- postfix r1++
	
	Rational& operator--(); // <-- prefix ++r1
	const Rational operator--( int ); // <-- postfix r1++


	//arithmetic unary operators

	Rational operator+() const
	{
		return *this; 
	}

	Rational operator-() const
	{
		return Rational(-numerator, denominator); 
	}
};

//outside operators realizations :

//arithmetic operators

//single operators + , - , * , / etc should not be friend functions , because 
//they use the public operators += and etc
//constant because a + b = c is not valid, copy because the result is a new object 


const Rational operator+( const Rational& lhs, const Rational& rhs );
const Rational operator-( const Rational& lhs, const Rational& rhs );
const Rational operator*( const Rational& lhs, const Rational& rhs );
const Rational operator/( const Rational& lhs, const Rational& rhs );


//comparators

//friend function of the class Rational, so it has access to private members

inline bool operator==( const Rational& lhs, const Rational& rhs )
{
	return ( lhs.numerator * rhs.denominator == lhs.denominator * rhs.numerator );
}

inline bool operator!=( const Rational& lhs, const Rational& rhs )
{
	return !(rhs == lhs);
}

inline bool operator<( const Rational& lhs, const Rational& rhs )
{
	return ( lhs.numerator * rhs.denominator < lhs.denominator * rhs.numerator );
}

inline bool operator>( const Rational& lhs, const Rational& rhs )
{
	return rhs < lhs;
}
inline bool operator<=( const Rational& lhs, const Rational& rhs )
{
	return !(lhs > rhs);
}
inline bool operator>=( const Rational& lhs, const Rational& rhs )
{
	return !(lhs < rhs);
}