#include "GameObj.hpp"
#include "Game.hpp"

GameObj::GameObj(const sf::Vector2f& pos, const sf::Vector2f& size)
    : m_shape(size)
{
    m_shape.setPosition(pos);
}


GameObj::GameObj(std::ifstream& in)
{
    sf::Vector2f pos;
    sf::Vector2f size;
    in.read((char*) &pos, sizeof(pos));
    in.read((char*) &size, sizeof(size));
    m_shape = sf::RectangleShape(size);
    m_shape.setPosition(pos);
}

void GameObj::draw() const
{
    Game::i().draw(m_shape);
}


void GameObj::drawGUI() const
{}


void GameObj::serialize(std::ofstream& file) const
{
    sf::Vector2f pos = m_shape.getPosition();
    sf::Vector2f size = m_shape.getSize();
    file.write((const char*) &pos, sizeof(pos));
    file.write((const char*) &size, sizeof(size));
}
