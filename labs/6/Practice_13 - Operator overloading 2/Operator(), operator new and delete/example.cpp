#include<iostream>
#include<fstream>
#include <cassert>
#include"Rational.h"

double linear(double a, double b, double x) { // we don't like this
	return a*x + b;
}

struct Linear
{
	double a, b;
	
	static int cntAlloc;

	void* operator new( size_t size )
	{
		std::cout << "Alloc " << size << " bytes" << std::endl;
		void* ptr = malloc( size );

		if ( !ptr )
		{
			throw std::bad_alloc();
		}

		cntAlloc++;
		return ptr;
	}

	void operator delete( void* ptr )
	{
		std::cout << "delete" << std::endl;
		cntAlloc--;
		if ( ptr )
		{
			free( ptr );
		}
	}


	double operator()( double x )
	{
		return a*x + b;
	}
};

int Linear::cntAlloc = 0;

void* operator new( size_t size )
{
	std::cout << "Alloc global " << size << " bytes" << std::endl;
	void* ptr = malloc( size );

	if ( !ptr )
	{
		throw std::bad_alloc();
	}

	return ptr;
}

void operator delete( void* ptr )
{
	std::cout << "delete global" << std::endl;
	if ( ptr )
	{
		free( ptr );
	}
}

struct Quadratic
{
	double a, b, c;

	double operator()( double x )
	{
		return a*x*x + b*x + c;
	}
};

int main() {

	Linear f{2, 1}; // Represents function 2x + 1.
	Linear g{-1, 0}; // Represents function -x.
					 // f and g are objects that can be used like a function.

	double f_0 = f(0); // this f is not a C++ function, but is function object and we use it as like function,
						//because we overloading operator()
	std::cout << "f(0) = " << f_0 << std::endl;
	double f_1 = f(1);
	std::cout << "f(1) = " << f_1 << std::endl;

	double g_0 = g(0);
	std::cout << "g(0) = " << g_0 << std::endl;


	Quadratic c { 5, 7, -5 };
	double c_5 = c(5);
	std::cout << "c(5) = " << c_5 << std::endl;


	//=============================================================================

	Linear* mClass = new Linear;
	delete mClass;

	Linear* mArr = new Linear[3];
	delete[] mArr;
	

	Quadratic* mArr1 = new Quadratic[3];
	delete[] mArr1;

	assert( Linear::cntAlloc == 0 ); // if this is true, means we have same amount of allocation and deletion and we alright


	return 0;
}