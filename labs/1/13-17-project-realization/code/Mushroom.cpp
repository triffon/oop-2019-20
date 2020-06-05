#include "Mushroom.hpp"

Mushroom::Mushroom(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , Enemy(pos, size)
{
    m_shape.setFillColor(sf::Color::Red);
}


void Mushroom::update()
{
    // Apply gravity
    PhysicsObj::update();

    // Apply basic AI
    Enemy::basicAI();

    // Move the enemy with the calculated speed
    move({ m_hspd, m_vspd });
}
