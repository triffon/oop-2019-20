#include <cstring>
#include <iostream>
#include "Soldier.hpp"

const char DEFAULT_SYM = 's';

Soldier::Soldier(const char* name, int hp)
    : Unit(hp)
    , m_name(nullptr)
{
    setName(name);
}


Soldier::Soldier(const Soldier& other)
    : Unit(other)
    , m_name(nullptr)
{
    setName(other.m_name);
}


Soldier& Soldier::operator=(const Soldier& other)
{
    setName(other.m_name);
    return *this;
}


Soldier::~Soldier()
{
    clear();
}


Coord Soldier::move() const
{
    return { -1, rand() % 2 == 0 ? -1 : 1 };
}


void Soldier::draw() const
{
    std::cout << DEFAULT_SYM;
}


void Soldier::getShot(int dmg)
{
    // TODO: Implement
    m_hp -= dmg;
}


void Soldier::setName(const char* name)
{
    delete[] m_name;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}


void Soldier::clear()
{
    delete[] m_name;
    m_name = nullptr;
}
