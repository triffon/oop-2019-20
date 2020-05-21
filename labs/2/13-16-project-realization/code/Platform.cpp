#include "Platform.hpp"
#include "Game.hpp"

Platform::Platform(sf::Vector2f pos, sf::Vector2f size)
    : Solid(pos, size)
    , m_shape(m_size)
{
    m_shape.setPosition(m_position);
    m_shape.setFillColor(sf::Color::Black);
}


void Platform::draw() const
{
    Game::i().draw(m_shape);
}
