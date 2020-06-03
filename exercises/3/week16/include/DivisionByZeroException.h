#ifndef DIVISIONBYZEROEXCEPTION_CPP
#define DIVISIONBYZEROEXCEPTION_CPP
//allows us to create our own exceptions
#include<exception>
class DivisionByZeroException : std::exception{
	float a;
	float b;
public:
	DivisionByZeroException(float a=0, float b=0);
	const char * what() const noexcept override;
};


#endif /* DIVISIONBYZEROEXCEPTION_CPP */
