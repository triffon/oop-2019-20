#include "Soldier.h"
#include <string.h>

Soldier::Soldier() : fName(nullptr), fAge(0), fSalary(0), fCombatSkills(0) {}

Soldier::Soldier( const char* name, unsigned short age, unsigned short salary, unsigned short combatSkills )
{
	this->init( name, age, salary, combatSkills );
}

Soldier::Soldier( const Soldier& other )
{
	this->copy( other );
}

Soldier& Soldier::operator=( const Soldier & other )
{
	if ( this != &other )
	{
		this->clean();
		this->copy( other );

	}
	return *this;
}

Soldier::~Soldier()
{
	this->clean();
}

void Soldier::copy( const Soldier & other )
{
	this->init( other.fName, other.fAge, other.fSalary, other.fCombatSkills );
}

void Soldier::clean()
{
	delete[] fName;
	fName = nullptr;
}

void Soldier::init( const char * name, unsigned short age, unsigned short salary, unsigned short combatSkills )
{
	fName = new char[ strlen( name ) + 1 ];
	strcpy( fName, name );

	fAge = age;
	fSalary = salary;
	fCombatSkills = combatSkills;
}

unsigned short Soldier::getSalary() const
{
	return fSalary;
}

unsigned short Soldier::getCombatSkills() const
{
	return fCombatSkills;
}

const char * Soldier::getName() const
{
	return fName;
}
