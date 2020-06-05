#include "GameObj.hpp"
#include "Game.hpp"

GameObj::GameObj(const sf::Vector2f& pos, const sf::Vector2f& size)
    : m_shape(size)
{
    m_shape.setPosition(pos);
}


void GameObj::draw() const
{
    Game::i().draw(m_shape);
}
