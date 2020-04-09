#pragma once
#include <string>
#include <stdexcept>

#include "Operations.hpp"
class Convert
{
private:
	static void validateStringToIntInput(const char* string);
public:
	static int stringToInt(const char* string);

	static Operations stringToOperation(const char operation);
};

