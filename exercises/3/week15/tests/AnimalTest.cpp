#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include"Animal.h"
#include<iostream>
using namespace std;

TEST(AnimalEat,givenMoreThanEnoughFoodEatIt){
	Animal a(25);
	Food f("Banana",10,2);
	a.eat(f,1);	
	EXPECT_EQ(a.getHealth(),27);
	EXPECT_EQ(f.getCount(),9);
}

TEST(AnimalEat,givenLessThanWantedFoodGiveMax){
	Animal a(25);
	Food f("Banana",10,2);
	a.eat(f,100);	
	EXPECT_EQ(a.getHealth(),45);
	EXPECT_EQ(f.getCount(),0);
}
TEST(AnimalGetHealth,givenValueToTheConstructorSetIt){
	Animal a(25);
	EXPECT_EQ(a.getHealth(),25);
}
