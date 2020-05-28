#include"Animal.h"
Animal::Animal(int health){
	this->health=health;
}
void Animal::eat(Food& f,int quantity){
	health+=f.eat(quantity);		
};
int Animal::getHealth()const{
	return health;
};
