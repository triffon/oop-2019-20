#pragma once

#include "Unit.hpp"
#include "IShootable.hpp"

class Soldier : public Unit, public IShootable
{
public:
    Soldier(const char* name = "Unnamed Soldier", int hp = 50);
    Soldier(const Soldier& other);
    Soldier& operator=(const Soldier& other);
    virtual ~Soldier() override;

    virtual Coord move() const override;
    virtual void draw() const override;
    virtual void getShot(int dmg) override;
    // virtual void getExploded(int dmg) override;

    void setName(const char* name);

private:
    void clear();

private:
    char* m_name;
};