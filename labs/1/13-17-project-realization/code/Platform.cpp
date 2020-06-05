#include "Platform.hpp"
#include "Game.hpp"

Platform::Platform(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Solid(pos, size)
{
    m_shape.setFillColor(sf::Color::Black);
}
