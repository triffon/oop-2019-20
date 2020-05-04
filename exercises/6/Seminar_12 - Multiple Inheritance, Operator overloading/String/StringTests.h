#pragma once
#include "String.h"

class StringTests
{
private:
	static void stringIsCreatedSuccessfullyWithDefaultConstructor();
	static void stringIsCreatedSuccessfullyWithNullPointerAsArgument();
	static void stringIsCreatedSuccessfullyFromCharSymbol();
	static void stringIsCreatedSuccessfullyFromCString();
	static void stringIsCreatedSuccessfullyWithCopyConstructor();
	static void stringIsCreatedSuccessfullyWithOperatorEquals();

	static void operatorPlusEqualsConcatenatesValueFromAnotherString();
	static void operatorPlusEqualsConcatenatesValueFromCharArray();
	static void operatorPlusEqualsConcatenatesValueFromChar();
				
	static void operatorPlusWorksWithAnotherString();
	static void operatorPlusWorksWithCharAsFirstArgument();
	static void operatorPlusWorksWithCharAsSecondArgument();
	static void operatorPlusWorksWithCharArrayAsFirstArgument();
	static void operatorPlusWorksWithCharArrayAsSecondArgument();
				
	static void operatorEqualsEqualsWorksWithAnotherString();
	static void operatorEqualsEqualsWorksWithCharAsFirstArgument();
	static void operatorEqualsEqualsWorksWithCharAsSecondArgument();
	static void operatorEqualsEqualsWorksWithCharArrayAsFirstArgument();
	static void operatorEqualsEqualsWorksWithCharArrayAsSecondArgument();
	
	static void operatorNotEqualsWorksWithAnotherString();

	static void operatorLessThanWorksWithAnotherString();
	static void operatorLessThanOrEqualsWorksWithAnotherString();
	static void operatorMoreThanWorksWithAnotherString();
	static void operatorMoreThanOrEqualsWorksWithAnotherString();

	static void serializationAndDesializationWorks(); // wtf with this one?

public:
	static void runAllTests();
};

