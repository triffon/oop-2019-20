#pragma once
#pragma warning(disable: 4996)

#include <string.h>
#include "Convert.hpp"

class StringCalculatorEngine
{
private:
	static void validateOperator(const char* operatorSymbol);
	static int executeOperation(Operations op, int first, int second);
public:
	static const char* evaluateExpression(const char* expr);
};

