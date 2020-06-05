#include "Crate.hpp"

Crate::Crate(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , Solid(pos, size)
    , PhysicsObj(pos, size)
    , Pushable(pos, size)
{
    m_shape.setFillColor(sf::Color(101, 67, 33));
}


void Crate::update()
{
    // Apply gravity
    PhysicsObj::update();

    // Move the crate
    move({ m_hspd, m_vspd });
}
