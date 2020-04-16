#include "General.h"
#include <iostream>
static const int reduceWith = 8;

General::General()
	: fDescription( nullptr ), fArmy( nullptr ), fSize( 0 ), fCapacity( 0 ) {}

General::General( const Soldier & warrior, const char * armyDescription, unsigned short capacity )
	: Soldier( warrior ), fSize( 0 ), fCapacity( capacity ),
	fDescription( nullptr ), fArmy( nullptr )
{
	this->init( armyDescription, capacity );
}

General::General( const char * name, unsigned short age, unsigned short salary,
	unsigned short combatSkills, const char * armyDescription, unsigned short capacity )
	: Soldier( name, age, salary, combatSkills ), fSize( 0 ), fCapacity( capacity )
	, fDescription( nullptr ), fArmy( nullptr)
{
	this->init( armyDescription, capacity );
}

General::~General()
{
	clean();
}

General::General( const General& warrior )
	: Soldier( warrior ), fDescription( nullptr ), fArmy( nullptr )
{
	this->init( warrior.fDescription, fCapacity );
}

General& General::operator=( const General& warrior )
{

	if ( this != &warrior )
	{

		Soldier::operator=( warrior );
		clean();
		copy( warrior );
	}

	return *this;
}

bool General::addComm( const Commander& warrior )
{

	if ( this->getCombatSkills() <= warrior.getCombatSkills() )
	{
		return false;
	}

	if ( fSize >= fCapacity )
	{
		if ( !resize() )
		{
			return false;
		}
	}

	fArmy[ fSize++ ] = warrior;
	return true;
}

unsigned int General::getArmySalary() const
{

	unsigned int armySalary = ( *this ).getSalary();

	for ( size_t i = 0; i < fSize; i++ )
		armySalary += fArmy[ i ].getSquadSalary();

	return armySalary;
}


unsigned int General::getArmyCombatSkills() const
{

	unsigned int armyCombatSkills = ( *this ).getCombatSkills();

	for ( size_t i = 0; i < fSize; i++ )
		armyCombatSkills += fArmy[ i ].getSquadCombatSkills();

	return armyCombatSkills;
}

unsigned int General::getArmyAverageCombatSkills() const
{

	unsigned int combatSkills = getArmyCombatSkills();
	unsigned int armySize = getArmySize();

	return combatSkills / armySize;
}

const char* General::getArmyDesc() const
{

	return fDescription;
}

const char* General::getName() const
{

	return fName;
}

unsigned int General::getArmySize() const
{

	unsigned int armySize = 1; // the commander

	for ( size_t i = 0; i < fSize; i++ )
		armySize += fArmy[ i ].getSquadSize();

	return armySize;
}

void General::copy( const General& warrior )
{

	fDescription = new ( std::nothrow ) char[ strlen( warrior.fDescription ) + 1 ];

	if ( !fDescription )
	{

		std::cerr << "Not enough memory to create new commander! \n";
		throw std::bad_alloc();
	}

	strcpy( fDescription, warrior.fDescription );

	fCapacity = warrior.fCapacity;
	fSize = warrior.fSize;
	fArmy = new( std::nothrow )Commander[ fCapacity ];

	if ( !fArmy )
	{
		std::cerr << "Not enough memory to create new army! \n";
		throw std::bad_alloc();
	}

	for ( size_t i = 0; i < fSize; i++ )
	{
		fArmy[ i ] = warrior.fArmy[ i ];
	}
}


bool General::resize()
{

	int biggerCapacity = fCapacity * 2;
	Commander* biggerArmy = nullptr;

	do
	{
		try
		{
			biggerArmy = new Commander[ biggerCapacity ];
		}
		catch ( std::bad_alloc & e )
		{
			biggerCapacity -= reduceWith;
		}

	}
	while ( ( biggerCapacity > fCapacity ) && !biggerArmy );

	if ( !biggerArmy )
	{
		std::cerr << "Not enough memory to resize the army! \n";
		return false;
	}

	for ( size_t i = 0; i < fSize; i++ )
	{
		biggerArmy[ i ] = fArmy[ i ];
	}


	delete[] fArmy;
	fArmy = biggerArmy;
	fCapacity = biggerCapacity;
	return true;
}

void General::clean()
{

	delete[] fDescription;
	fDescription = nullptr;
	delete[] fArmy;
	fArmy = nullptr;
}

void General::init( const char* desc, size_t capacity )
{
	try
	{
		fDescription = new char[ strlen( desc ) + 1 ];
		strcpy( fDescription, desc );
		fArmy = new Commander[ capacity ];
	}
	catch ( std::bad_alloc& )
	{
		Soldier::clean();
		General::clean();

		std::cerr << "Not enough memory to create new army! \n";
		throw;
	}
}