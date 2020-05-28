#include<iostream>
#include"Food.h"
Food::Food(std::string name, int count, int nutritionalValue){
	this->name = name;
	this->count = count;
	this->nutritionalValue = nutritionalValue;
};

//Takes the amount of the specified food to be eaten and returns the nutritionalValue from the eaten food
int Food::eat(int count){
	int result = std::min(count,this->count)*nutritionalValue;
	this->count -= std::min(count,this->count);
	return result;
}; 

//Get how much nutritional value is there in the whole object
int Food::getTotalNutritionalValue()const{
	return nutritionalValue*count;
}; 
std::string Food::getName()const{
	return name;
};

int Food::getCount()const{
	return count;
}
