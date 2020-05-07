#pragma once

#include "Prop.hpp"

class Bush : public Prop
{
public:
    Bush() = default;
    Bush(int hp) : Prop(hp) {}

    virtual void draw() const override;
    // virtual void getExploded(int dmg) override;
};