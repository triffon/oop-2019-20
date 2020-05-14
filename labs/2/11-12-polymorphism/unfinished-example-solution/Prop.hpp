#pragma once

#include "Entity.hpp"

class Prop : public Entity
{
public:
    Prop(int hp = 1) : Entity(hp) {}
    virtual void draw() const override;
    // virtual void getShot(int dmg) override;
    // virtual void getExploded(int dmg) override;
};