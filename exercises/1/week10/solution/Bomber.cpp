#include "Bomber.h"

Bomber::Bomber()
	:Starship("Bomber", 40)
{
	for (int i = 0; i < 10; i++)
	{
		bombs[i] = new Bomb();
	}
}


Bomber::~Bomber()
{
	for (int i = 0; i < bombs_count; i++)
	{
		delete bombs[i];
	}
}


void Bomber::attack()
{
	if (bombs_count > 0)
	{
		cout << "Bomber: dropping bomb" << endl;
		delete bombs[--bombs_count];
		bombs[bombs_count] = nullptr;
		weight_in_tons -= 2;
	}
	else
	{
		cout << "Bomber: not enough bombs" << endl;
	}
}


void Bomber::printInfo()
{
	cout << "Bomber Info:" << endl;
	cout << "  bombs: "<< bombs_count << endl;
	cout << "  weight: " << weight_in_tons << endl;
}