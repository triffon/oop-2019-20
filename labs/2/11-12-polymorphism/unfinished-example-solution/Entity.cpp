#include <iostream>
#include "Entity.hpp"

const char DEFAULT_SYM = ' ';

Entity::Entity(int hp)
    : m_hp(hp)
{}


void Entity::draw() const
{
    std::cout << DEFAULT_SYM;
}


void Entity::getShot(int dmg)
{
    m_hp -= dmg;
}


void Entity::getExploded(int dmg)
{
    m_hp -= dmg;
}
