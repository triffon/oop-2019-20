//
// Created by yasen on 2/22/20.
//


#include <iostream>
#include <climits>
#include <limits>
#include "Planet.h"

Planet enterPlanet() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter information of the planet:" << std::endl;
    Planet planet;
    std::cout << "Name of the planet: ";
    std::cin.getline(planet.name, NAME_SIZE);
    std::cout << "Distance to Sun: ";
    std::cin >> planet.distanceToSun;
    std::cout << "Diameter: ";
    std::cin >> planet.diameter;
    std::cout << "Mass: ";
    std::cin >> planet.mass;

    return planet;
}

void printPlanet(const Planet& planet) {
    std::cout << "Name: " << planet.name << std::endl;
    std::cout << "Distance to Sun: " << planet.distanceToSun << std::endl;
    std::cout << "Diameter: " << planet.diameter << std::endl;
    std::cout << "Mass: " << planet.mass << std::endl;
}

ull_int secondToSum(const Planet& planet) {
    const ull_int lightSpeed = 299782ull;
    return planet.distanceToSun / lightSpeed;
}

Planet* theClosestOneToSum(Planet planets[], size_t size) {
    size_t minIndex = 0;
    for (size_t i = 1; i < size; ++i) {
        if(planets[minIndex].distanceToSun > planets[i].distanceToSun) {
            minIndex = i;
        }
    }
    return &planets[minIndex];
}

void theClosestTwo(Planet planets[], size_t size, Planet& outFirst, Planet& outSecond) {
    for (int i = 0; i < size-1; ++i) {
        size_t minIndex = i;
        for (int j = i+1; j < size; ++j) {
            if(planets[minIndex].distanceToSun > planets[j].distanceToSun) {
                minIndex = j;
            }
        }
        if(i != minIndex) {
            std::swap(planets[i], planets[minIndex]);
        }
    }

    ull_int minDistance = ULONG_LONG_MAX;
    size_t firstIndex = (size_t)-1;
    for (int k = 0; k < size-1; ++k) {
        if(planets[k+1].distanceToSun - planets[k].distanceToSun < minDistance) {
            firstIndex = k;
        }
    }
    outFirst = planets[firstIndex];
    outSecond = planets[firstIndex+1];
}

void initPlanets(Planet* planets, size_t size) {
    for (int i = 0; i < size; ++i) {
        planets[i] = enterPlanet();
    }
}
