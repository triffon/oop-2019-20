#include "VisualDetails.h"
#include <string.h>
#include <iostream>


VisualDetails::VisualDetails() : fDoorCount(0), fHasWing(false)
{
	strcpy( fColor, "" );
}

VisualDetails::VisualDetails( unsigned int doorCount, bool hasWing, const char* color) : // обикновен инициализиращ списък
	fDoorCount(doorCount),
	fHasWing(hasWing)
{
	std::cout << "Constuctor VisualDetails" << std::endl;
	strcpy( fColor, color ); // Препоръчително да се изкопира по този начин
}


// Не е задължителен, защото нямаме динамичма памет, която да трием
VisualDetails::~VisualDetails()
{
	std::cout << "Destructor VisualDetails" << std::endl;
}

void VisualDetails::print() const
{
	std::cout << "Count Doors: " << fDoorCount << std::endl;
	std::cout << ( fHasWing ? "Has wing" : "Doesn't have wing" ) << std::endl;
	std::cout << "Color: " << fColor << std::endl;
}

void VisualDetails::readFromConsole()
{
	std::cout << "Enter number of doors: ";
	std::cin >> fDoorCount;
	std::cout << "Enter 0 if the car has no wing, otherwise - 1: ";
	std::cin >> fHasWing;

	std::cin.ignore();
	std::cout << "Enter color: ";
	std::cin.getline(fColor, MAX_SIZE );
}

void VisualDetails::setColor( const char* newColor )
{
	memset( fColor, 0, MAX_SIZE + 1 );
	strcpy( fColor, newColor );
}
