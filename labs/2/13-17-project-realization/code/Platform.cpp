#include "Platform.hpp"
#include "Game.hpp"

const size_t ID = 2;
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


size_t Platform::getSaveId()
{
    return ID;
}


void Platform::seriallize(std::ofstream& file) const
{
    size_t id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    Solid::seriallize(file);
}
