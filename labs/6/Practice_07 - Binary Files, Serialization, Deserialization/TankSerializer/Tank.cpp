#include "Tank.h"
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

Tank::Tank( const char * name, unsigned int shotPower, unsigned int lifePoints )
{
	init( name, shotPower, lifePoints );
}

Tank::Tank( const Tank & other )
{
	if ( this != &other )
	{
		copyFrom( other );
	}
}

Tank& Tank::operator=( const Tank & other )
{
	if ( this != &other )
	{
		clean();
		copyFrom( other );
	}
	return *this;
}

Tank::~Tank()
{
	this->clean();
}

void Tank::serialize( ofstream& ofs ) const
{
	if ( !ofs.is_open() )
	{
		cout << "File is not open" << endl;
		return;
	}
	size_t lenght = strlen( fName );
	ofs.write( (const byte*) &lenght, sizeof( size_t ) );
	ofs.write( fName, lenght * sizeof(byte) /* = lenght*/);

	ofs.write( (const byte*) &fShotPower, sizeof( unsigned int ) );
	ofs.write( (const byte*) &fLifePoints, sizeof( unsigned int ) );

	if (ofs.good())
		cout << "Successfully serialize" << endl;
	else
		cout << "Serialize failed" << endl;
}

void Tank::deserialize( std::ifstream& ifs )
{
	if ( !ifs.is_open() )
	{
		cout << "File is not open" << endl;
		return;
	}
	size_t length = 0;
	ifs.read( (byte*) &length, sizeof( size_t ) );
	fName = new byte[ length + 1 ];
	if ( fName )
	{
		ifs.read( fName, length );
		fName[ length ] = '\0';
	}

	ifs.read( (byte*) &fShotPower, sizeof( unsigned int ) );
	ifs.read( (byte*) &fLifePoints, sizeof( unsigned int ) );

	if (ifs.good())
		cout << "Successfully deserialize" << endl;
	else
		cout << "Deserialize failed" << endl;
}

void Tank::tankInfo() const
{
	cout << "Name: \t"			<< fName		<< endl <<
			"shotPower: \t"		<< fShotPower	<< endl <<
			"lifePoints: \t"	<< fLifePoints	<< endl;
}

const char* Tank::getName() const
{
	return fName;
}
unsigned int Tank::getShotPower() const
{
	return fShotPower;
}
unsigned int Tank::getLifePoints() const
{
	return fLifePoints;
}

void Tank::setName( char* newName )
{
	size_t size = strlen( newName );
	delete[] fName;
	fName = new char[ size + 1 ];
	strcpy( fName, newName );
}
void Tank::setShotPower(unsigned int shotPower) {
	this->fShotPower = shotPower;
}
void Tank::setLifePoints(unsigned int lifePoints) {
	this->fLifePoints = lifePoints;
}

void Tank::init( const char * name, unsigned int shotPower, unsigned int lifePoints )
{
	fName = new char[ strlen( name ) + 1 ];
	if ( fName )
	{
		strcpy( fName, name );
	}
	fShotPower = shotPower;
	fLifePoints = lifePoints;
}

void Tank::clean()
{
	delete[] fName;
}

void Tank::copyFrom( const Tank& other )
{
	this->init( other.fName, other.fShotPower, other.fLifePoints );
}
