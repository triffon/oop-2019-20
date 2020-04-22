#include "Farm.h"



Farm::Farm(): allAnimals( nullptr ), size( 0 )
{

}

Farm::Farm( const Farm& other )
{
	allAnimals = new Animal*[ other.size ];
	for (int i = 0; i < other.size; ++i)
	{
		allAnimals[ i ] = other.allAnimals[ i ]->clone();
	}
	
	size = other.size;
}

Farm& Farm::operator=( const Farm & other )
{

	if ( this != &other )
	{

		clear();
		allAnimals = new Animal*[ other.size ];
		for ( int i = 0; i < other.size; ++i )
		{
			allAnimals[ i ] = other.allAnimals[ i ]->clone();
		}

		size = other.size;
		
	}

	return *this;
}


Farm::~Farm()
{

	clear();
}

void Farm::clear()
{
	for ( int i = 0; i < size; ++i )
	{
		delete allAnimals[ i ];
	}

	delete[] allAnimals;
	allAnimals = nullptr;
	size = 0;
}

void Farm::addAnimal( Animal* newAnimal )
{
	if ( newAnimal == nullptr )
	{
		throw std::invalid_argument( "null pointer passed" );
	}

	Animal** newAnimals = new Animal*[ size + 1 ];

	for ( int i = 0; i < size; ++i )
	{
		newAnimals[ i ] = allAnimals[ i ];
	}
	newAnimals[ size ] = newAnimal;
	++size;
	delete[] allAnimals;
	allAnimals = newAnimals;
	
}

void Farm::allSounds()
{
	for ( int i = 0; i < size; ++i )
	{
		allAnimals[ i ]->makeSound();
	}
	
}