#include "ManufactureDetails.h"
#include <string.h>
#include <iostream>

#define MAX_BUFF (1 << 10)

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

void ManufactureDetails::readFromConsole()
{
	std::cout << "Enter a name of manufacture: " << std::endl;
	char name[ MAX_BUFF + 1 ];
	std::cin.getline( name, MAX_BUFF );
	
	std::cout << "Enter a name of model: " << std::endl;
	char model[ MAX_BUFF + 1 ];
	std::cin.getline( model, MAX_BUFF );
	
	std::cout << "Еnter the year of production: " << std::endl;
	unsigned int year;
	std::cin >> year;

	this->init( name, model, year );
}

void ManufactureDetails::init( const char* name, const char* model, unsigned int year)
{
	if ( name )
	{
		fName = new char[ strlen(name) + 1 ];
		strcpy( fName, name );
	}
	if ( model )
	{
		fModel = new char[ strlen(model) + 1 ];
		strcpy( fModel, model );
	}

	if ( year < CAR_FIRST_YEAR  )
	{
		fYear = CAR_FIRST_YEAR;
	} 
	else if ( year >  CURRENT_YEAR )
	{
		fYear = CURRENT_YEAR;
	}
	else
	{
		fYear = year;
	}
}

void ManufactureDetails::clean()
{
	delete[] fName;
	delete[] fModel;
	fYear = 0;
}
