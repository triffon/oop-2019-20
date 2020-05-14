#pragma once

#include "Unit.hpp"

class Tank : public Unit
{
public:
    Tank(int hp = 1000) : Unit(hp) {}
    virtual void draw() const override;
    // virtual void getShot(int dmg) override;
    // virtual void getExploded(int dmg) override;

    virtual Coord move() const override;
};