#include "Crate.hpp"

const size_t ID = 3;
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


size_t Crate::getSaveId()
{
    return ID;
}


void Crate::seriallize(std::ofstream& file) const
{
    size_t id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    PhysicsObj::seriallize(file);
}
