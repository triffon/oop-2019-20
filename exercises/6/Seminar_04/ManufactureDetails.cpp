#include "ManufactureDetails.h"
#include <string.h>
#include <iostream>

ManufactureDetails::ManufactureDetails()
{
	std::cout << "Default Constuctor ManufactureDetails" << std::endl;
	this->init( "", "", 0 );
}

ManufactureDetails::ManufactureDetails( const char* name, const char* model, unsigned int year) :
	fName(new char[ strlen(name) + 1 ])
{
	std::cout << "Constuctor with parameters ManufactureDetails" << std::endl;
	this->init( name, model, year );
}

ManufactureDetails::ManufactureDetails( const ManufactureDetails& other)
{
	std::cout << "Copy Constuctor ManufactureDetails" << std::endl;
	if ( this != &other )
	{
		this->init( other.fName, other.fModel, other.fYear );
	}
}

ManufactureDetails& ManufactureDetails::operator=( const ManufactureDetails& other )
{
	std::cout << "operator= ManufactureDetails" << std::endl;
	if ( this != &other )
	{
		this->clean();
		this->init( other.fName, other.fModel, other.fYear );
	}
	return *this;
}

ManufactureDetails::~ManufactureDetails()
{
	std::cout << "Destructor ManufactureDetails" << std::endl;
	this->clean();
}

//=================================================================

void ManufactureDetails::print() const
{
	std::cout << fName << std::endl;
	std::cout << fModel << std::endl;
	std::cout << fYear << std::endl;
}

void ManufactureDetails::init( const char* name, const char* model, unsigned int year)
{
	fName = new char[ strlen(name) + 1 ];
	strcpy( fName, name );
	fModel = new char[ strlen(model) + 1 ];
	strcpy( fModel, model );

	fYear = year;
}

void ManufactureDetails::clean()
{
	delete[] fName;
	delete[] fModel;
	fYear = 0;
}
