#pragma once

#include "Entity.hpp"
#include "Coord.hpp"

class Unit : public Entity
{
public:
    Unit(int hp = 100) : Entity(hp) {}
    virtual void draw() const override;
    // virtual void getShot(int dmg) override;
    // virtual void getExploded(int dmg) override;

    virtual Coord move() const = 0;
};