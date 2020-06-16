#include "Platform.hpp"
#include "Game.hpp"

const unsigned char ID = 'p';
const sf::Color DEFAULT_COLOR = sf::Color::Black;

Platform::Platform(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Solid(pos, size)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


Platform::Platform(std::ifstream& in)
    : GameObj(in)
    , Solid(in)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


unsigned char Platform::getSaveId()
{
    return ID;
}


void Platform::serialize(std::ofstream& file) const
{
    unsigned char id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    Solid::serialize(file);
}
