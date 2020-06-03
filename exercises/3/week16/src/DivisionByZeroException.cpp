#include<DivisionByZeroException.h>
#include<iostream>
#include<cstring>
#include<sstream>
DivisionByZeroException::DivisionByZeroException(float a, float b):a(a),b(b){
};
const char * DivisionByZeroException::what() const noexcept {
	std::ostringstream s;
	s << "Division by zero exception. User tried with the values "  << a << " and " << b;
	char * result = new char[s.str().length()+1];
	std::strcpy(result,s.str().c_str());
	return result;
};

