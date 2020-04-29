#pragma once


class Starship
{
	char *type = nullptr;

protected:
	int weight_in_tons = 0;
public:
	Starship(const char *_type, int _weight_in_tons);
	void printType();
	virtual void attack() = 0;
	virtual void printInfo() = 0;

	virtual ~Starship();

};
