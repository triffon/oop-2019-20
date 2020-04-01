#pragma once
#include "Tank.h"

class Army
{
	Tank* fArmy;
	size_t fSize;
	size_t fCapacity;

public:

	Army(size_t capacity = 1);
	Army(const Army& other);
	Army& operator=( const Army& other );
	~Army();

	size_t getCurrSize() const;
	size_t getCapacity() const;


public:
	void addTank( const Tank& newTank );
	void remove(Tank& tank);

	void sortingTanks();

	void attack(Tank& target);

	void serialize( ofstream& ofs ) const;
	void deserialize( ifstream& ifs );

	void print() const;
private:
	void clean();
	void copyFrom( const Army& other );
	void resize( size_t newCap );
};

