#include "Car.h"
#include <iostream>

Car::Car()
{
	std::cout << "Default Constuctor Car" << std::endl;
}

Car::Car( unsigned int horsePower, double volume, EngineType type,
		unsigned int doorCount, bool hasWing, const char * color,
		const char * name, const char * model, unsigned int year,
		bool isNew, unsigned int price ) :
		fEngineDetails(horsePower, volume, type), // Тук се вика констуктора с параметри на EngineDetails класа
		fVisualDetails(doorCount, hasWing, color), // Тук се вика констуктора с параметри на VisualDetails класа
		fManufactureDetails(name, model, year), // Тук се вика констуктора с параметри на ManufactureDetails класа
		fIsNew(isNew), fPrice(price) // Останалите параметри се инициализират при създаването също
{
	std::cout << "Constuctor Car" << std::endl;
}

Car::Car( const EngineDetails& engineDetails,
		const VisualDetails & visualDetails, 
		const ManufactureDetails & manufactureDetails, 
		bool isNew, unsigned int price ) : 
		fEngineDetails(engineDetails), // Тук се вика дефоутния копи констуктор на EngineDetails класа
		fVisualDetails(visualDetails), // Тук се вика дефоутния копи констуктор на VisualDetails класа
		fIsNew(isNew), fPrice(price)
		// Също така се вика и дефоутния констуктор на ManufactureDetails, за да се създаде полето fManufactureDetails
{
	fManufactureDetails = manufactureDetails; // след като вече е създадено полето, тук се вика operator= на ManufactureDetails класа
	
	std::cout << "Constuctor Car" << std::endl;
}

// Не е задължителен, защото нямаме динамичма памет, която да трием
// Нищо, че някой от полетата на класа са обекти съдържащи динамична памет, 
// при (автоматичното) викане на този деструктор, ще се викнат(пак автоматично)
// и деструкторите на класовете на съответните полета
Car::~Car()
{
	std::cout << "Destructor Car" << std::endl;
}

void Car::print() const
{
	std::cout << "Price: " << fPrice << std::endl;
	std::cout << ( fIsNew ? "Is new" : "Not new" ) << std::endl;
	fEngineDetails.print();
	fVisualDetails.print();
	fManufactureDetails.print();
}

void Car::readFromConsole()
{
	std::cout << "Enter information for one car: " << std::endl;
	fEngineDetails.readFromConsole();
	fVisualDetails.readFromConsole();
	fManufactureDetails.readFromConsole();
	std::cout << "Enter 0 if the car is old, otherwise - 1: ";
	std::cin >> fIsNew;
	std::cout << "Enter price: ";
	std::cin >> fPrice;
	std::cout << "====================================" << std::endl;
}
