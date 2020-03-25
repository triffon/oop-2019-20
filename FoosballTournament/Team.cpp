#include "Team.hpp"

Team::Team() {}

Team::Team(SoftwareEngineer _first, SoftwareEngineer _second) : first(_first), second(_second) {}

bool Team::isValid() const
{
	bool firstIsValid = first.isValid();
	bool secondIsValid = second.isValid();

	return firstIsValid && secondIsValid;
}

int Team::getCeoCount() const
{
	int ceoCount = first.ceoCount() + second.ceoCount();

	return ceoCount;
}

int Team::getCtoCount() const
{
	int ctoCount = first.ctoCount() + second.ctoCount();

	return ctoCount;
}

void Team::print() const
{
	std::cout << "Team Rocket: " << std::endl;
	first.print();
	second.print();
}
