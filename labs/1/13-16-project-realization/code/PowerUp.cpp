#include "PowerUp.hpp"

PowerUp::PowerUp(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Collectable(pos, size)
{
    m_shape.setFillColor(sf::Color(sf::Color::Magenta.r, sf::Color::Magenta.g, sf::Color::Magenta.b, 75));
}
