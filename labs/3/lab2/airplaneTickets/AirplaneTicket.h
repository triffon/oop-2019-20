//
// Created by tony on 27.02.20 г..
//

#ifndef FMIOOP_AIRPLANETICKET_H
#define FMIOOP_AIRPLANETICKET_H

#include <iostream>
#include <cstring>
#include "Person.h"
class AirplaneTicket {
    bool businessClass;
    char startingPoint[32];
    char destination[32];
    char date[16];
    int flightSeat;
    int duration;
    double price;
    Person holder;

public:
    void fillTicketInformation();

    void changeDate(const char* date,
                    double price,
                    bool businessClass);

    void printTicket() const;

    const char *getStartingPoint() const;

    const char *getDestination() const;

    double getPrice() const;

    int getFlightSeat() const;

    int getDuration() const;

    int getHolderAge() const;

    bool getBusinessClass() const;

    const char *getDate() const;

    const char *getHolderFirstName() const;

    const char *getHolderSurname() const;

    const char *getHolderFamilyName() const;

    void changePerson(const Person &second);

};

#endif //FMIOOP_AIRPLANETICKET_H
