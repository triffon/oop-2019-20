#include "Army.h"
#include <iostream>

using std::cout;
using std::endl;

Army::Army( size_t capacity )
{
	if ( capacity == 0 )
	{
		capacity = 1;
	}
	fArmy = new Tank[ capacity ];
	fSize = 0;
	fCapacity = capacity;
}

Army::Army( const Army& otherArmy )
{
	if ( this != &otherArmy )
	{
		copyFrom( otherArmy );
	}
}

Army& Army::operator=( const Army& otherArmy )
{
	if ( this != &otherArmy )
	{
		clean();
		copyFrom( otherArmy );
	}
	return *this;
}

Army::~Army()
{
	clean();
}

void Army::addTank( const Tank& newTank )
{
	if ( fSize >= fCapacity )
	{
		size_t newCap = ( fCapacity == 0 ) ? 2 : fCapacity * 2;
		resize( newCap );
	}
	fArmy[ fSize++ ] = newTank;
}

void Army::remove( Tank& tank )
{
	std::swap(tank, fArmy[fSize]);
	fSize--;
}

void Army::sortingTanks()
{
	for ( int i = 0; i < fSize - 1; ++i )
	{
		for ( int j = i + 1; j < fSize; ++j )
		{
			if ( fArmy[ i ].getShotPower() < fArmy[ j ].getShotPower() )
				std::swap( fArmy[ i ], fArmy[ j ] );
		}
	}
}

void Army::attack( Tank & target )
{
	sortingTanks();
	size_t countTanks = 0;
	double tankLifePoints = target.getLifePoints();
	for ( int i = 0; i < fSize; ++i )
	{
		if ( tankLifePoints > 0.0 )
		{
			tankLifePoints -= fArmy[ i ].getShotPower();
			countTanks++;
		}
	}
	std::cout << "CountTanks: " << countTanks << std::endl;
	if ( countTanks > 0 )
	{
		for ( int i = 0; i < countTanks; ++i )
		{
			target.setLifePoints( target.getLifePoints() - fArmy[ i ].getShotPower() );
		}
		if ( target.getLifePoints() <= 0.0 )
		{
			std::cout << "Tank has been destroyed\nTank info:\n";
			target.tankInfo();
			this->remove( target );
		}
	}
	else
	{
		std::cout << "Not enough power on army" << std::endl;
		return;
	}

}

void Army::serialize( std::ofstream& ofs ) const
{
	if ( !ofs.is_open() )
	{
		return;
	}

	ofs.write( (const byte*) &fSize, sizeof( size_t ) );
	ofs.write( (const byte*) &fCapacity, sizeof( size_t ) );

	for ( size_t i = 0; i < fSize; i++ )
	{
		fArmy[ i ].serialize( ofs );
	}
}

void Army::deserialize( std::ifstream & ifs )
{
	if ( !ifs.is_open() )
	{
		return;
	}

	ifs.read( (byte*) &fSize, sizeof( size_t ) );
	ifs.read( (byte*) &fCapacity, sizeof( size_t ) );

	clean();
	fArmy = new Tank[ fCapacity ];
	for ( size_t i = 0; i < fSize; i++ )
	{
		fArmy[ i ].deserialize( ifs );
	}
}

void Army::print() const
{
	std::cout << "Size: " << fSize <<
		"\nCapacity: " << fCapacity << std::endl;

	for ( size_t i = 0; i < fSize; i++ )
	{
		fArmy[ i ].tankInfo();
	}
}

size_t Army::getCurrSize() const
{
	return fSize;
}

size_t Army::getCapacity() const
{
	return fCapacity;
}

void Army::clean()
{
	delete[] fArmy;
}

void Army::copyFrom( const Army& other )
{
	fArmy = new Tank[ other.fCapacity ];
	for ( size_t i = 0; i < other.fSize; i++ )
	{
		fArmy[ i ] = other.fArmy[ i ];
	}

	fSize = other.fSize;
	fCapacity = other.fCapacity;
}

void Army::resize(size_t newCap)
{
	if ( newCap <= fSize )
	{
		return;
	}
	Tank* tempArmy = new Tank[ newCap ];

	for ( size_t i = 0; i < fSize; i++ )
	{
		tempArmy[ i ] = fArmy[ i ];
	}

	delete[] fArmy;
	fArmy = tempArmy;
	fCapacity = newCap;
}
