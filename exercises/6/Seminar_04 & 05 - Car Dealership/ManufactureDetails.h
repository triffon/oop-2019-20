#pragma once

#define CURRENT_YEAR (2020)

class ManufactureDetails
{
	char* fName;
	char* fModel;
	unsigned int fYear;

public:
	// THE BIG 4
	// Предефинираме си дефоутните констуктори, оператор= и деструктор, 
	// защото имаме динамична памет и трябва да се погрижим сами за паметта.
	// Тези методи осигуряват правилният life cycle на обектите от този тип
	ManufactureDetails();
	ManufactureDetails( const char*, const char*, unsigned int );
	ManufactureDetails( const ManufactureDetails& );
	ManufactureDetails& operator=( const ManufactureDetails& );
	~ManufactureDetails();

	void print() const;
	void readFromConsole();
private:
	void init( const char*, const char*, unsigned int );
	void clean();
};

