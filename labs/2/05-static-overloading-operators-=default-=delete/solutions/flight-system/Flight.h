#pragma once
#include <iostream>
#include <fstream>

class Flight
{
public:
    Flight(const char* departure = "", const char* destination = "", double price = 0);
    Flight(const Flight& other);
    Flight& operator=(const Flight& other);
    ~Flight();

    inline const char* getDeparture() const { return departure; }
    inline const char* getDestination() const { return destination; }
    inline double getPrice() const { return price; }
    inline unsigned getId() const { return id; }

    friend std::ostream& operator<<(std::ostream& out, const Flight& obj);

private:
    void copy(const Flight& other);
    void clear();

    static unsigned getID();
    static unsigned currID;

    unsigned id;
    char* departure;
    char* destination;
    double price;
};
