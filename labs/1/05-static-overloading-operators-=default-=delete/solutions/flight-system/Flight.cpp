#include <cstring>
#include "Flight.h"

unsigned Flight::currID = 0;

unsigned Flight::getID()
{
    return currID++;
}


Flight::Flight(const char* departure, const char* destination, double price)
    : id(getID())
    , departure(new char[strlen(departure) + 1])
    , destination(new char[strlen(destination) + 1])
    , price(price)
{
    strcpy(this->departure, departure);
    strcpy(this->destination, destination);
}


Flight::Flight(const Flight& other)
{
    copy(other);
}


Flight& Flight::operator=(const Flight& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Flight::~Flight()
{
    clear();
}


std::ostream& operator<<(std::ostream& out, const Flight& obj)
{
    return out << obj.departure << " -> " << obj.destination << " ($" << obj.price << ")";
}


void Flight::copy(const Flight& other)
{
    departure = new char[strlen(other.departure) + 1];
    strcpy(departure, other.departure);
    destination = new char[strlen(other.destination) + 1];
    strcpy(destination, other.destination);
    id = getID();
    price = other.price;
}


void Flight::clear()
{
    delete[] departure;
    delete[] destination;
    departure = nullptr;
    destination = nullptr;
}
