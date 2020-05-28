#ifndef FOOD_H
#define FOOD_H
#include<string>
class Food{
	std::string name; // the name of the food 
	int count;
	int nutritionalValue;
public:
	Food(std::string name="", int count=0, int nutritionalValue=0);
	virtual int eat(int count); //Takes the amount of the specified food to be eaten and returns the nutritionalValue from the eaten food
	int getTotalNutritionalValue()const; //Get how much nutritional value is there in the whole object
	std::string getName()const;
	int getCount()const;
};


#endif /* FOOD_H */
