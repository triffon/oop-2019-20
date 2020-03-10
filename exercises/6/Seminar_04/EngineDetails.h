#pragma once


// Повече за enum class vs enum
// https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/

enum class EngineType
{
	Diesel = 0,
	Petrol,
	Hybrid,
	Electric,
};

struct EngineDetails
{
	unsigned int fHorsePower;
	double fVolume;
	EngineType fEngineType;


	EngineDetails( unsigned int, double, EngineType );
	~EngineDetails();
};

