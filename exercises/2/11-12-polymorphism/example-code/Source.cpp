#include <iostream>
#include "Vehicle.hpp"
#include "Garage.hpp"


class Car : public Vehicle
{
public:
    virtual void drive() override {
        std::cout << "Car driven\n";
    }

    virtual Vehicle* clone() const {
        return new Car(*this);
    }
};


class ElectricCar : public Car
{
public:
    virtual void drive() final override {
        std::cout << "Electric car driven\n";
    }

    virtual Vehicle* clone() const {
        return new ElectricCar(*this);
    }
};


class Bike : public Vehicle
{
public:
    virtual void drive() final override {
        std::cout << "Bike ridden\n";
    }

    virtual Vehicle* clone() const {
        return new Bike(*this);
    }
};


struct Exm {
    void f(const int& b) const {
        int* ptr = const_cast<int*>(&b);
        *ptr = 10;
        std::cout << b;

        Exm* pExm = const_cast<Exm*>(this);
        pExm->mem = 10;
    }

    int mem;
};


int main()
{
    Garage garage;

    garage.addVehicle(new Car);
    garage.addVehicle(new ElectricCar);
    garage.addVehicle(new Bike);
    garage.addVehicle(new ElectricCar);
    garage.addVehicle(new Car);
    garage.addVehicle(new Car);
    garage.addVehicle(new Bike);
    garage.addVehicle(new Car);

    garage.showAll();

    std::cout << garage.count<Car>() << " cars\n";

    return 0;
}
