#pragma once
#include "Soldier.h"
#include "Commander.h"


class General : public Soldier
{
	char* fDescription;
	Commander* fArmy;
	unsigned short fSize;
	unsigned short fCapacity;

public:

	General();
	General( const Soldier& other, const char* armyDescription, unsigned short capacity = 16 );
	General( const char* name, unsigned short age, unsigned short salary,
			unsigned short combatSkills, const char* armyDescription, unsigned short capacity = 16 );
	General( const General& other );
	General& operator=( const General& other );
	~General();

private:

	unsigned int getArmySize() const;

	void copy( const General& warrior );
	bool resize();
	void clean();
	void init( const char* desc, size_t fCapacity );

public:

	bool addComm( const Commander& warrior );

	unsigned int getArmySalary() const;
	unsigned int getArmyCombatSkills() const;
	unsigned int getArmyAverageCombatSkills() const;

	const char* getArmyDesc() const;
	const char* getName() const;

};

