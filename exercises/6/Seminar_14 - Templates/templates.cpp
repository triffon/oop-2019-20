#include <iostream>
#include "Box.hpp"

using namespace std;

template<typename T>
const T& max( const T& a, const T& b )
{
	return a < b ? b: a;
}


template<typename T>
void swap( T& lhs, T& rhs )
{
	std::cout << "my swap" << std::endl;
	T temp = lhs ;
	lhs = rhs;
	rhs = temp;
}

template<typename T>
const T* max( const T* a, const T* b )
{
	return a < b ? b: a;
}


template<>
const int& max( const int& a, const int& b )
{
	return a < b ? b: a;
}

template<>
const char* max( const char* a, const char* b )
{
	return strcmp(a, b) <= 0 ? b: a;
}

struct A
{
	int x;

	bool operator<( const A& rhs ) const
	{
		return this->x < rhs.x;
	}

	friend std::ostream& operator<<( std::ostream& os, const A& a );
};


std::ostream& operator<<( std::ostream& os, const A& a )
{
	os << a.x << std::endl;
	return os;
}


template<class T, class U>
struct pair
{
	T first;
	U second;
};


int main()
{
	std::cout << max( 5, 7 ) << std::endl;
	std::cout << max<int>( 5, 7 ) << std::endl;

	std::cout << max( 5.6, 7.9 ) << std::endl;
	//const char* str = "abv";
	std::cout << max( "abc", "abd" ) << std::endl;

	A a1 { 5 }, a2 { 8 };

	std::cout << max( a1, a2 ) << std::endl;
	
	return 0;
}