#include "StringCalculatorEngine.hpp"

void StringCalculatorEngine::validateOperator(const char* operatorSymbol)
{
	// "+-*/%^" a b + - 
	const char* allOperators = "+-*/%^";
	const char* errorMessageEnd = " is not one of the possible operators.";
	char* possibleErrorMessage = new char[strlen(operatorSymbol) + strlen(errorMessageEnd) + 1];
	strcpy(possibleErrorMessage, operatorSymbol);
	strcat(possibleErrorMessage, errorMessageEnd);

	size_t length = strlen(operatorSymbol);
	if (length != 1 || strstr(allOperators, operatorSymbol) == nullptr)
	{
		throw std::invalid_argument(possibleErrorMessage);
	}

	delete[] possibleErrorMessage;
}

int StringCalculatorEngine::executeOperation(Operations op, int first, int second)
{
	switch (op)
	{
	case Operations::Addition:
		return first + second;
	case Operations::Substraction:
		return first - second;
	case Operations::Multiplication:
		return first * second;
	case Operations::Division:
		return first / second;
	case Operations::Modulo:
		return first % second;
	case Operations::Exponent:
		return pow(first, second);
	default:
		throw std::invalid_argument("Invalid operation.");
	}

	return 0;
}

const char* StringCalculatorEngine::evaluateExpression(const char* expr)
{
	const char* delimiter = " ";
	char* expression = new char[strlen(expr) + 1];
	char* exprBeginning = expression;
	strcpy(expression, expr);

	char* firstArgument;
	char* secondArgument;
	char* operatorSymbol;

	firstArgument = strtok(expression, delimiter);
	operatorSymbol = strtok(NULL, delimiter);
	secondArgument = strtok(NULL, delimiter);

	int first = Convert::stringToInt(firstArgument);
	int second = Convert::stringToInt(secondArgument);
	StringCalculatorEngine::validateOperator(operatorSymbol);
	Operations operation = Convert::stringToOperation(operatorSymbol[0]);

	int  result = StringCalculatorEngine::executeOperation(operation, first, second);

	delete[] expression;
	auto res = std::to_string(result);
	auto res2 = res.c_str();

	char* stringResult = new char[strlen(res2) + 1];
	strcpy(stringResult, res2);
	return stringResult;
}
