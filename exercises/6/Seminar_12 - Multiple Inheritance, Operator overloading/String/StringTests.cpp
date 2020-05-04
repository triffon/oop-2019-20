#include "StringTests.h"
#include <cassert>
#include <sstream>

void StringTests::stringIsCreatedSuccessfullyWithDefaultConstructor()
{
	const char* expectedValue = "";

	String string;
	const char* result = string.ToDynamicCharArray();

	assert(strcmp(result, expectedValue) == 0);
	delete[] result;
}

void StringTests::stringIsCreatedSuccessfullyWithNullPointerAsArgument()
{
	const char* expectedValue = "";

	String string = String(nullptr);
	const char* result = string.ToDynamicCharArray();

	assert(strcmp(result, expectedValue) == 0);
	delete[] result;
}

void StringTests::stringIsCreatedSuccessfullyFromCharSymbol()
{
	char expectedValue[2] = { 'c','\0' };

	String string = String(expectedValue[0]);
	const char* result = string.ToDynamicCharArray();

	assert(strcmp(result, expectedValue) == 0);
	delete[] result;
}

void StringTests::stringIsCreatedSuccessfullyFromCString()
{
	const char* expectedValue = "ABC";

	String string = String(expectedValue);
	const char* result = string.ToDynamicCharArray();

	assert(strcmp(result, expectedValue) == 0);
	delete[] result;
}

void StringTests::stringIsCreatedSuccessfullyWithCopyConstructor()
{
	const char* expectedValue = "ABC";

	String string = String(expectedValue);
	String copy = string;
	const char* result = copy.ToDynamicCharArray();

	assert(strcmp(result, expectedValue) == 0);
	delete[] result;
}

void StringTests::stringIsCreatedSuccessfullyWithOperatorEquals()
{
	const char* expectedValue = "ABC";

	String string = String(expectedValue);
	String operatorEqualsCopy;
	operatorEqualsCopy = string;
	const char* result = operatorEqualsCopy.ToDynamicCharArray();

	assert(strcmp(result, expectedValue) == 0);
	delete[] result;
}

void StringTests::operatorPlusEqualsConcatenatesValueFromAnotherString()
{
	const char* expectedValue = "ABC123";
	const char* secondValue = "123";
	String first = "ABC";
	String second = secondValue;

	first += second;
	const char* firstCharArray = first.ToDynamicCharArray();
	const char* secondCharArray = second.ToDynamicCharArray();

	assert(strcmp(firstCharArray, expectedValue) == 0);
	assert(strcmp(secondCharArray, secondValue) == 0);

	delete[] firstCharArray;
	delete[] secondCharArray;
}

void StringTests::operatorPlusEqualsConcatenatesValueFromCharArray()
{
	const char* expectedValue = "ABC123";
	const char* second = "123";
	String first = "ABC";

	first += second;
	const char* firstCharArray = first.ToDynamicCharArray();

	assert(strcmp(firstCharArray, expectedValue) == 0);
	delete[] firstCharArray;
}

void StringTests::operatorPlusEqualsConcatenatesValueFromChar()
{
	const char* expectedValue = "ABC1";
	const char second = '1';
	String first = "ABC";

	first += second;
	const char* firstCharArray = first.ToDynamicCharArray();

	assert(strcmp(firstCharArray, expectedValue) == 0);
	delete[] firstCharArray;
}

void StringTests::operatorPlusWorksWithAnotherString()
{
	const char* firstValue = "ABC";
	const char* secondValue = "123";
	const char* expectedValue = "ABC123";

	String first = firstValue;
	String second = secondValue;

	String result = first + second;
	const char* firstCharArray = first.ToDynamicCharArray();
	const char* secondCharArray = second.ToDynamicCharArray();
	const char* resultCharArray = result.ToDynamicCharArray();

	assert(strcmp(firstCharArray, firstValue) == 0);
	assert(strcmp(secondCharArray, secondValue) == 0);
	assert(strcmp(resultCharArray, expectedValue) == 0);

	delete[] firstCharArray;
	delete[] secondCharArray;
	delete[] resultCharArray;
}

void StringTests::operatorPlusWorksWithCharAsFirstArgument()
{
	const char first = 'A';
	const char* secondValue = "123";
	const char* expectedValue = "A123";

	String second = secondValue;
	String result = first + second;

	const char* resultCharArray = result.ToDynamicCharArray();
	const char* secondCharArray = second.ToDynamicCharArray();

	assert(strcmp(secondCharArray, secondValue) == 0);
	assert(strcmp(resultCharArray, expectedValue) == 0);

	delete[] secondCharArray;
	delete[] resultCharArray;
}

void StringTests::operatorPlusWorksWithCharAsSecondArgument()
{
	const char* firstValue = "123";
	const char second = 'A';
	const char* expectedValue = "123A";

	String first = firstValue;
	String result = first + second;

	const char* resultCharArray = result.ToDynamicCharArray();
	const char* firstCharArray = first.ToDynamicCharArray();

	assert(strcmp(firstCharArray, firstValue) == 0);
	assert(strcmp(resultCharArray, expectedValue) == 0);

	delete[] firstCharArray;
	delete[] resultCharArray;
}

void StringTests::operatorPlusWorksWithCharArrayAsFirstArgument()
{
	const char* firstValue = "123";
	const char* secondValue = "ABC";
	const char* expectedValue = "123ABC";

	String second = secondValue;
	String result = firstValue + second;

	const char* resultCharArray = result.ToDynamicCharArray();
	const char* secondCharArray = second.ToDynamicCharArray();

	assert(strcmp(secondCharArray, secondValue) == 0);
	assert(strcmp(resultCharArray, expectedValue) == 0);

	delete[] secondCharArray;
	delete[] resultCharArray;
}

void StringTests::operatorPlusWorksWithCharArrayAsSecondArgument()
{
	const char* firstValue = "123";
	const char* secondValue = "ABC";
	const char* expectedValue = "123ABC";

	String first = firstValue;
	String result = first + secondValue;

	const char* resultCharArray = result.ToDynamicCharArray();
	const char* firstCharArray = first.ToDynamicCharArray();

	assert(strcmp(firstCharArray, firstValue) == 0);
	assert(strcmp(resultCharArray, expectedValue) == 0);

	delete[] firstCharArray;
	delete[] resultCharArray;
}

void StringTests::operatorEqualsEqualsWorksWithAnotherString()
{
	const char* value = "ABC";

	String first = value;
	String second = value;

	assert(first == second);
}

void StringTests::operatorEqualsEqualsWorksWithCharAsFirstArgument()
{
	const char c = 'C';
	String string = c;

	assert(c == string);
}

void StringTests::operatorEqualsEqualsWorksWithCharAsSecondArgument()
{
	const char c = 'C';
	String string = c;

	assert(string == c);
}

void StringTests::operatorEqualsEqualsWorksWithCharArrayAsFirstArgument()
{
	const char* value = "ABC";
	String string = value;

	assert(value == string);
}

void StringTests::operatorEqualsEqualsWorksWithCharArrayAsSecondArgument()
{
	const char* value = "ABC";
	String string = value;

	assert(string == value);
}

void StringTests::operatorNotEqualsWorksWithAnotherString()
{
	String first = "ABC";
	String second = "ABCDEF";

	assert(first != second);
}

void StringTests::operatorLessThanWorksWithAnotherString()
{
	String first = "ABC";
	String second = "ABCDEF";

	assert(first < second);
}

void StringTests::operatorLessThanOrEqualsWorksWithAnotherString()
{
	String first = "ABC";
	String second = "ABCDEF";

	assert(first <= second);
}

void StringTests::operatorMoreThanWorksWithAnotherString()
{
	String first = "ABCDEF";
	String second = "ABC";

	assert(first > second);
}

void StringTests::operatorMoreThanOrEqualsWorksWithAnotherString()
{
	String first = "ABCDEF";
	String second = "ABC";

	assert(first >= second);
}

void StringTests::serializationAndDesializationWorks()
{
	std::stringstream ss;
	String serialized = "YEP";
	String deserialized;

	ss << serialized;
	ss >> deserialized;

	assert(serialized == deserialized);
}

void StringTests::runAllTests()
{
	stringIsCreatedSuccessfullyWithDefaultConstructor();
	stringIsCreatedSuccessfullyWithNullPointerAsArgument();
	stringIsCreatedSuccessfullyFromCharSymbol();
	stringIsCreatedSuccessfullyFromCString();
	stringIsCreatedSuccessfullyWithCopyConstructor();
	stringIsCreatedSuccessfullyWithOperatorEquals();

	operatorPlusEqualsConcatenatesValueFromAnotherString();
	operatorPlusEqualsConcatenatesValueFromCharArray();
	operatorPlusEqualsConcatenatesValueFromChar();

	operatorPlusWorksWithAnotherString();
	operatorPlusWorksWithCharAsFirstArgument();
	operatorPlusWorksWithCharAsSecondArgument();
	operatorPlusWorksWithCharArrayAsFirstArgument();
	operatorPlusWorksWithCharArrayAsSecondArgument();

	/*operatorEqualsEqualsWorksWithAnotherString();
	operatorEqualsEqualsWorksWithCharAsFirstArgument();
	operatorEqualsEqualsWorksWithCharAsSecondArgument();
	operatorEqualsEqualsWorksWithCharArrayAsFirstArgument();
	operatorEqualsEqualsWorksWithCharArrayAsSecondArgument();

	operatorNotEqualsWorksWithAnotherString();

	operatorLessThanWorksWithAnotherString();
	operatorLessThanOrEqualsWorksWithAnotherString();
	operatorMoreThanWorksWithAnotherString();
	operatorMoreThanOrEqualsWorksWithAnotherString();
	*/
	serializationAndDesializationWorks();
}
