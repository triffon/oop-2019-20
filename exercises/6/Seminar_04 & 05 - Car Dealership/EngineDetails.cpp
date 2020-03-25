#include "EngineDetails.h"
#include <iostream>

EngineDetails::EngineDetails() : fHorsePower(0), fVolume(0), fEngineType(EngineType::Unknown)
{
}

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

void EngineDetails::print() const
{
	std::cout << "Horse power: " << fHorsePower << std::endl;
	std::cout << "Volume: " << fVolume << std::endl;
	std::cout << "Engine Type: ";
	switch ( fEngineType )
	{
		case EngineType::Diesel:
			std::cout << "Diesel" << std::endl;
			break;
		case EngineType::Electric:
			std::cout << "Electric" << std::endl;
			break;
		case EngineType::Hybrid:
			std::cout << "Hybrid" << std::endl;
			break;
		case EngineType::Petrol:
			std::cout << "Petrol" << std::endl;
			break;
		default:
			std::cout << "Unknown" << std::endl;
	}

}

void EngineDetails::readFromConsole()
{
	std::cout << "Enter horse power: ";
	std::cin >> fHorsePower;
	std::cout << "Enter volume: ";
	std::cin >> fVolume;

	std::cin.ignore();
	std::cout << "Enter type of engine[Diesel/Petrol/Hybrid/Electric]: ";
	
	char type[ 10 ];
	std::cin.getline( type, 10 );
	if ( strcmp( type, "Diesel" ) == 0 )
	{
		fEngineType = EngineType::Diesel;
	}
	else if ( strcmp( type, "Petrol" ) == 0 )
	{
		fEngineType = EngineType::Petrol;
	}
	else if ( strcmp( type, "Hybrid" ) == 0 )
	{
		fEngineType = EngineType::Hybrid;
	}
	else if ( strcmp( type, "Electric" ) == 0 )
	{
		fEngineType = EngineType::Electric;
	}
	else
	{
		fEngineType = EngineType::Unknown;
	}
}
