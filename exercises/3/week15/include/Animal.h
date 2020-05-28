#ifndef ANIMAL_H
#define ANIMAL_H
#include"Food.h"
class Animal{
	int health;
public:
	Animal(int health=0);
	void eat(Food& f,int quantity);
	int getHealth()const;
};


#endif /* ANIMAL_H */
