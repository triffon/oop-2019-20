#pragma once

class Entity
{
public:
    Entity(int hp = 1000);
    virtual void draw() const;
    virtual void getExploded(int dmg);
    inline int getHealth() const { return m_hp; }

    virtual ~Entity() = default;

protected:
    int m_hp;
};
