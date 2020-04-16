#pragma once

#include "Soldier.h"

class Commander : public Soldier
{
	Soldier* fSquad;
	size_t fSize;
	size_t fCapacity;
	char* fDescription;

public:
	Commander();
	Commander( const char* name, unsigned short age, unsigned short salary, unsigned short combatSkills,
					const char* desc, size_t fCapacity = 16 );
	Commander( const Soldier& soldier, const char* desc, size_t fCapacity = 16 );
	Commander( const Commander& other );
	Commander& operator=( const Commander& other );
	~Commander();


private:
	void copy( const Commander& other );
	void clean();
	void init( const char* desc, size_t fCapacity );
	bool resize();

public:
	bool addSoldier( const Soldier& soldier );
	unsigned int getSquadSalary() const;
	unsigned int getSquadSize() const;
	unsigned int getSquadCombatSkills() const;
	
};

