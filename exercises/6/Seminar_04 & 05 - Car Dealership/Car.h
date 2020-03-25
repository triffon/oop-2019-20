#pragma once

#include "ManufactureDetails.h"
#include "VisualDetails.h"
#include "EngineDetails.h"


class Car
{
public:
	Car();
	Car(unsigned int horsePower, double volume, EngineType type,
		unsigned int doorCount, bool hasWing, const char* color,
		const char* name, const char* model, unsigned int year,
		bool isNew, unsigned int price);
	Car( const EngineDetails& engineDetails, const VisualDetails& visualDetails,
		const ManufactureDetails& manufactureDetails, bool isNew, unsigned int price );

	~Car();

	void print() const;
	void readFromConsole();
private:
	EngineDetails fEngineDetails;
	VisualDetails fVisualDetails;
	ManufactureDetails fManufactureDetails;
	bool fIsNew;
	unsigned int fPrice;

};
