#include "Door.hpp"

const size_t COLORS_COUNT = 5;
const sf::Color COLORS[] = { sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue, sf::Color::Green, sf::Color::Red };
const unsigned char MAX_DOOR_ID = '9';
const unsigned char MIN_DOOR_ID = '5';

Door::Door(const sf::Vector2f& pos, unsigned char doorId, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Solid(pos, size)
    , m_color(COLORS[MAX_DOOR_ID - doorId])
{
    m_shape.setFillColor(m_color);
}


Door::Door(std::ifstream& in)
    : GameObj(in)
    , Solid(in)
{
    in.read((char*) &m_color, sizeof(m_color));
    m_shape.setFillColor(m_color);
}


unsigned char Door::getMinId()
{
    return MIN_DOOR_ID;
}


unsigned char Door::getMaxId()
{
    return MAX_DOOR_ID;
}


unsigned char Door::getSaveId()
{
    return getMaxId();
}


void Door::serialize(std::ofstream& file) const
{
    unsigned char id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    Solid::serialize(file);

    file.write((const char*) &m_color, sizeof(m_color));
}
