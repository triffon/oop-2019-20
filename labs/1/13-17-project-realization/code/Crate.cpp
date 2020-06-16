#include "Crate.hpp"

const unsigned char ID = 'c';
const sf::Color DEFAULT_COLOR = sf::Color(101, 67, 33);

Crate::Crate(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , Solid(pos, size)
    , PhysicsObj(pos, size)
    , Pushable(pos, size)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


Crate::Crate(std::ifstream& in)
    : GameObj(in)
    , Entity(in)
    , Solid(in)
    , PhysicsObj(in)
    , Pushable(in)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


void Crate::update()
{
    // Apply gravity
    PhysicsObj::update();

    // Move the crate
    move({ m_hspd, m_vspd });
}


unsigned char Crate::getSaveId()
{
    return ID;
}


void Crate::serialize(std::ofstream& file) const
{
    unsigned char id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    PhysicsObj::serialize(file);
}
