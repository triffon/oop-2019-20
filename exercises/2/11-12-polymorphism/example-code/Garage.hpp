#pragma once

#include <vector>
#include "Vehicle.hpp"

class Garage
{
public:
    Garage() = default;
    Garage(const Garage& other);
    Garage& operator=(const Garage& other);
    ~Garage();

    void addVehicle(Vehicle* vehicle);
    void showAll() const;

    Vehicle* operator[](size_t index);
    const Vehicle* operator[](size_t index) const;

    template <class T>
    size_t count() const;

private:
    void clear();
    void copy(const Garage& other);

    std::vector<Vehicle*> vec;
};


template<class T>
size_t Garage::count() const
{
    size_t result = 0;
    for (size_t i = 0; i < vec.size(); i++)
        if (typeid(*vec[i]) == typeid(T))
            ++result;

    return result;
}
