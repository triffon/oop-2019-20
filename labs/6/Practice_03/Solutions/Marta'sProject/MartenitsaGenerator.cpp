//
// Created by yasen on 3/8/20.
//

#include <time.h>
#include <stdlib.h>
#include "MartenitsaGenerator.h"

const size_t countNames = 8;
const char* names[countNames] = {"Yasen", "Gosho", "Victor", "Niki", "Gabi", "Victoria", "Tedi", "Andi"};

const size_t countWishes = 5;
const char* wishes[countWishes] = {"Zdrave", "Mnogo shtastie", "Mnogo 6ci", "Zavurshvane na FMI", "Lubov"};


MartenitsaGenerator::MartenitsaGenerator(size_t length, size_t countBeads)
    : defaultLength(length)
    , defaultCountBeads(countBeads) {
    srand(time(NULL));
    if(length == 0) {
        defaultLength = rand() % 20 + 10;
    }

    if(countBeads == 0) {
        defaultCountBeads = rand() % 20 + 10;
    }
}

Martenitsa MartenitsaGenerator::generate() {
    return Martenitsa(names[rand()%countNames], wishes[rand()%countWishes],defaultLength, defaultCountBeads);
}

Martenitsa MartenitsaGenerator::generateByName(const char* name) {
    return Martenitsa(name, wishes[rand()%countWishes], defaultLength, defaultCountBeads);
}

Martenitsa MartenitsaGenerator::generateByWish(const char* wish) {
    return Martenitsa(names[rand()%countNames], wish, defaultLength, defaultCountBeads);
}

Martenitsa MartenitsaGenerator::generateByNameAndWish(const char* name, const char* wish) {
    return Martenitsa(name, wish, defaultLength, defaultCountBeads);
}

void MartenitsaGenerator::generateList(size_t count) {
    if( count < list.getCapacity() ){
        for (int i = 0; i < count; ++i) {
            list.add(this->generate());
        }
    }
}

void MartenitsaGenerator::generateListByName(const char *name, size_t count) {
    if( count < list.getCapacity() ){
        for (int i = 0; i < count; ++i) {
            list.add(this->generateByName(name));
        }
    }
}

void MartenitsaGenerator::generateListByWish(const char *wish, size_t count) {
    if( count < list.getCapacity() ){
        for (int i = 0; i < count; ++i) {
            list.add(this->generateByWish(wish));
        }
    }
}

void MartenitsaGenerator::generateListByNameAndWish(const char *name, const char *wish, size_t count) {
    if( count < list.getCapacity() ){
        for (int i = 0; i < count; ++i) {
            list.add(this->generateByNameAndWish(name, wish));
        }
    }
}
