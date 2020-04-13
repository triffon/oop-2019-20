#include <iostream>
#include "extended_namespace.hpp"
// https://en.cppreference.com/w/cpp/language/namespace

namespace apple
{
	void f( const char* string )
	{
		std::cout << string << std::endl;
	}

	int var;

	struct A
	{
		double d;
	};
}

void h( const char* string )
{
	std::cout << string << std::endl;
}

namespace orange
{
	void f( const char* string )
	{
		std::cout << string << std::endl;
	}

	int var;

	struct A
	{
		double d;

		
	};

	void g()
	{
		::h( "Hello from g()" ); // This search signatures from global scope
	}
}



int main()
{
	apple::f( "Hello" );
	orange::f( "Hello" );
	apple::f1( "Hello extended" ); // This function is from other file, from extended namespace apple

	apple::A objApple;
	objApple.d = 5;
	orange::A objApple;
	objApple.d = 8;

	using namespace apple; // this name of namespace we may not write anymore below that line
	f( "using namespace apple" ); // and I cat call the function like this, or any signature from that namespace

	// check the video in the README.md file for namespaces from more examples


	return 0;
}
