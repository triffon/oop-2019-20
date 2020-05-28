#include "Crate.hpp"

Crate::Crate(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Solid(pos, size)
{
    m_shape.setFillColor(sf::Color(101, 67, 33));
}
