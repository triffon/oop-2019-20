#include <iostream>
#include "StringTests.h"
#include "String.h"
int main()
{
	String string = "Hello, World!";
	String a = String("Hello, ");
	String b = String("World!");
	String string2 = a + b;
	String string3 = a + "World";
	String string4 = "Hello, " + b;
	if ("Test" == string)
	{

	}
	std::cout << string2.ToDynamicCharArray() << std::endl;
	StringTests::runAllTests();
}
