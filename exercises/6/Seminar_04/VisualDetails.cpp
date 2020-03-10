#include "VisualDetails.h"
#include <string.h>
#include <iostream>


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

void VisualDetails::setColor( const char* newColor )
{
	memset( fColor, 0, MAX_SIZE + 1 );
	strcpy( fColor, newColor );
}
