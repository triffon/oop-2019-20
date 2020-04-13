#pragma once
#include "Vector.h"

class System {

public:
    static System& i();

    System(const System&) = delete;
    void operator=(const System&) = delete;

    void setStartingMoney(double money);
    void createFlight(const char* departure, const char* destination, double price);
    void deleteFlight(unsigned flightId);
    void searchFlight(const char* departure, const char* destination) const;
    void signup(unsigned flightId);
    void printMoney() const;
    void printAll() const;
    void printSigned() const;
    void printHelp() const;
    ~System();

    void run();

private:
    System();
    int getIndexFromId(unsigned flightId) const;

    Vector allFlights;
    Vector signedFlights;
    double money;
    bool moneySet;
};