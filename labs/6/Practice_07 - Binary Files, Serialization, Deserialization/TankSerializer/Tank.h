#pragma once
#include <fstream>

#define byte char

using std::ofstream;
using std::ifstream;

class Tank
{
	char* fName;
	unsigned int fShotPower;
	unsigned int fLifePoints;

public:
	Tank( const char* name = "", unsigned int shotPower = 0, unsigned int lifePoints = 0 );
	Tank( const Tank& other );
	Tank& operator=( const Tank& other );
	~Tank();

public:
	void serialize( ofstream& ofs ) const;
	void deserialize( ifstream& ifs );

	void tankInfo() const;
	const char* getName() const;
	unsigned int getShotPower() const;
	unsigned int getLifePoints() const;
	void setName( char* name );
	void setShotPower( unsigned int shotPower );
	void setLifePoints( unsigned int LifePoints );

private:
	void init( const char* name, unsigned int shotPower, unsigned int lifePoints );
	void clean();
	void copyFrom( const Tank& other );
};

