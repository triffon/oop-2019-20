#pragma once



class Soldier
{
protected:
	char* fName;
	unsigned short fAge;
	unsigned short fSalary;
	unsigned short fCombatSkills;
	
public:
	Soldier();
	Soldier( const char* name, unsigned short age, unsigned short salary, unsigned short combatSkills );
	Soldier( const Soldier& other );
	Soldier& operator=( const Soldier& other );
	~Soldier();

protected:
	void copy( const Soldier& other );
	void clean();

	void init( const char* name, unsigned short age, unsigned short salary, unsigned short combatSkills );

public:
	unsigned short getSalary() const;
	unsigned short getCombatSkills() const;
	const char* getName() const;
};

