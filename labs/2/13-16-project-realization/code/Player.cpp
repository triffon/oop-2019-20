#include "Player.hpp"
#include "Game.hpp"

Player::Player(sf::Vector2f pos, sf::Vector2f size)
    : PhysicsObj(pos, size)
    , m_shape(m_size)
{
    m_shape.setPosition(m_position);
    m_shape.setFillColor(sf::Color::Green);
}


void Player::draw() const
{
    Game::i().draw(m_shape);
}


void Player::update()
{
    // Use the Physics Object gravity
    PhysicsObj::update();

    // TODO: Add code for player movement

    // Drawing object position change
    m_shape.setPosition(m_position);
}