#include "EngineDetails.h"
#include <iostream>

EngineDetails::EngineDetails( unsigned int horsePower, double volume, EngineType type) : // обикновен инициализиращ списък
	fHorsePower(horsePower),
	fVolume(volume),
	fEngineType(type)
{
	std::cout << "Constuctor EngineDetails" << std::endl;
}

// Не е задължителен, защото нямаме динамичма памет, която да трием
EngineDetails::~EngineDetails()
{
	std::cout << "Destructor EngineDetails" << std::endl;
}
