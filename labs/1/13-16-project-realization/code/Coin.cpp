#include "Coin.hpp"

Coin::Coin(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Collectable(pos, size)
{
    m_shape.setFillColor(sf::Color::Yellow);
}
