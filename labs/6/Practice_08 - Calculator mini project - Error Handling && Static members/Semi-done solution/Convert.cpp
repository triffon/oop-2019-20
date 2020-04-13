#include "Convert.hpp"

void Convert::validateStringToIntInput(const char* string)
{
	const char* errorMessageEnd = " was not a number.";
	char* possibleErrorMessage = new char[strlen(string) + strlen(errorMessageEnd) + 1];
	strcpy(possibleErrorMessage, string);
	strcat(possibleErrorMessage, errorMessageEnd);

	size_t length = strlen(string);

	for (size_t i = 0; i < length; i++)
	{
		if (string[i] < '0' || string[i] > '9')
		{
			throw std::invalid_argument(possibleErrorMessage);
		}
	}
}

int Convert::stringToInt(const char* string)
{
	validateStringToIntInput(string);
	int result = std::stoi(string);

	return result;
}

Operations Convert::stringToOperation(const char operation)
{
	switch (operation)
	{
	case '+':
		return Operations::Addition;
	case '-':
		return Operations::Substraction;
	case '*':
		return Operations::Multiplication;
	case '/':
		return Operations::Division;
	case '%':
		return Operations::Modulo;
	case '^':
		return Operations::Exponent;
	default:
		throw std::invalid_argument("Operator is invalid.");
	}

	return Operations::Unknown;
}
