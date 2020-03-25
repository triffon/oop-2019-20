#include "Dealership.h"
#include <iostream>

Dealership::Dealership( size_t capacity ) : fSize(0), fCapacity(capacity)
{
	fCars = new Car[ fCapacity ];
}

Dealership::Dealership( const Dealership& other )
{
	if ( this != &other )
	{
		this->copyFrom( other );
	}
}

Dealership& Dealership::operator=( const Dealership& other )
{
	if ( this != &other )
	{
		this->clean();
		this->copyFrom( other );
	}
	return *this;
}

Dealership::~Dealership()
{
	std::cout << "Destructor Dealership" << std::endl;
	this->clean();
}

void Dealership::addCar( const Car& newCar )
{
	std::cout << "Adding Car" << std::endl;
	if ( fSize == fCapacity )
	{
		this->resize( fCapacity * 2 );
	}
	fCars[ fSize ] = newCar;
	fSize++;
}

void Dealership::print() const
{
	std::cout << "Size: " << fSize << std::endl;
	std::cout << "Capacity: " << fCapacity << std::endl;

	for ( size_t i = 0; i < fSize; i++ )
	{
		fCars[ i ].print();
	}
}

void Dealership::readFromConsole()
{
	std::cout << "Enter capacity of dealership: ";
	std::cin >> fCapacity;
	for ( size_t i = 0; i < fCapacity; i++ )
	{
		fCars[ i ].readFromConsole();
	}
	fSize = fCapacity;
}

void Dealership::clean()
{
	delete[] fCars;
}

void Dealership::copyFrom( const Dealership& other )
{
	fSize = other.fSize;
	fCapacity = other.fCapacity;

	fCars = new Car[ other.fCapacity ];

	for ( size_t i = 0; i < other.fSize; i++ )
	{
		fCars[ i ] = other.fCars[ i ];
	}
}

void Dealership::resize( size_t newCapacity )
{
	std::cout << "Resize Dealership" << std::endl; 
	Car* buff = new (std::nothrow) Car[ newCapacity ];

	if ( buff )
	{
		for ( size_t i = 0; i < fSize; i++ )
		{
			buff[ i ] = fCars[ i ];
		}

		this->clean();
		fCapacity = newCapacity;
		fCars = buff;
	}
}
