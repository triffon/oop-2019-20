#pragma once

#include "Prop.hpp"
#include "IShootable.hpp"

class Barrel : public Prop, public IShootable
{
public:
    Barrel() = default;
    Barrel(int hp) : Prop(hp) {}

    virtual void draw() const override;
    virtual void getShot(int dmg) override;
    // virtual void getExploded(int dmg);
};