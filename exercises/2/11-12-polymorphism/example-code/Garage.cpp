#include "Garage.hpp"


Garage::Garage(const Garage& other)
{
    copy(other);
}


Garage& Garage::operator=(const Garage& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Garage::~Garage()
{
    clear();
}


void Garage::addVehicle(Vehicle* vehicle)
{
    vec.push_back(vehicle);
}


void Garage::showAll() const
{
    for (size_t i = 0; i < vec.size(); i++)
        vec[i]->drive();
}


Vehicle* Garage::operator[](size_t index)
{
    return vec[index];
}


const Vehicle* Garage::operator[](size_t index) const
{
    return vec[index];
}


void Garage::clear() {
    for (size_t i = 0; i < vec.size(); i++)
        delete vec[i];
}


void Garage::copy(const Garage& other) {
    vec.reserve(other.vec.size());
    for (size_t i = 0; i < other.vec.size(); i++)
        vec.push_back(other.vec[i]->clone());
}
