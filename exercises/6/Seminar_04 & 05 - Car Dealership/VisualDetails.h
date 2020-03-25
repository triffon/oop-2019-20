#pragma once

#define MAX_SIZE (50)

struct VisualDetails
{
	unsigned int fDoorCount;
	bool fHasWing;
	char fColor[ MAX_SIZE + 1 ];

	VisualDetails();
	VisualDetails( unsigned int, bool, const char* );
	~VisualDetails();

	void print() const;
	void readFromConsole();
	// Всичко в тази структура е публично, но все пак може да си направим set-ар за цвета, нищо че имаме достъп до fColor
	void setColor( const char* );

};
