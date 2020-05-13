#include <iostream>
#include "Vector.h"
#include <cassert>

int main();

void initializeVectorFromFile(std::string filename, VectorN& vector);

void testAddition(const VectorN& lhs, const VectorN& rhs);
void testSubstraction1(const VectorN& lhs, const VectorN& rhs);
void testSubstraction2(const VectorN& lhs, const VectorN& rhs);
void testScalarMultiplication(const VectorN& lhs);
void testScalarProductException(const VectorN& lhs, const VectorN& rhs);
void testScalarProduct(const VectorN& lhs, const VectorN& rhs);
void testVectorToString(const VectorN& vector);
int main()
{
	VectorN lhs;
	VectorN rhs;
	VectorN third;
	try
	{
		initializeVectorFromFile("input_01.txt", lhs);
		initializeVectorFromFile("input_02.txt", rhs);
		initializeVectorFromFile("input_03.txt", third);
		testVectorToString(lhs);
		testAddition(lhs, rhs);
		testAddition(rhs, lhs);
		testSubstraction1(lhs, rhs);
		testSubstraction2(rhs, lhs);
		testScalarMultiplication(lhs);
		testScalarProductException(lhs, rhs);
		testScalarProduct(rhs, third);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void initializeVectorFromFile(std::string filename, VectorN& vector)
{
	std::ifstream in(filename);

	if (!in.is_open())
	{
		throw filename + "could not be opened.";
	}

	in >> vector;
}

void testAddition(const VectorN& lhs, const VectorN& rhs)
{
	VectorN result = lhs + rhs;

	assert(result.toString() == "[3, 3, 3, 1]");
}

void testSubstraction1(const VectorN& lhs, const VectorN& rhs)
{
	VectorN result = lhs - rhs;
	assert(result.toString() == "[-1, -1, -1, 1]");
}

void testSubstraction2(const VectorN& lhs, const VectorN& rhs)
{
	VectorN result = lhs - rhs;
	assert(result.toString() == "[1, 1, 1, -1]");
}

void testScalarMultiplication(const VectorN& lhs)
{
	VectorN result = lhs * 5;
	assert(result.toString() == "[5, 5, 5, 5]");

	result = 5 * lhs;
	assert(result.toString() == "[5, 5, 5, 5]");
}

void testScalarProductException(const VectorN& lhs, const VectorN& rhs)
{
	// 1 1 1 1 % 2 2 2 0
	try
	{
		VectorN result = lhs % rhs;
	}
	catch (std::exception & e)
	{
		assert(strcmp(e.what(), "Invalid dimensions.") == 0);
	}

}

void testScalarProduct(const VectorN& lhs, const VectorN& rhs)
{
	VectorN result = lhs % rhs;

	assert(result.toString() == "[4, 4, 4]");
}

void testVectorToString(const VectorN& vector)
{
	std::string result = vector.toString();
	assert(result == "[1, 1, 1, 1]");
}
