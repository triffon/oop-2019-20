#include "Button.hpp"
#include "Player.hpp"
#include "Door.hpp"

const size_t COLORS_COUNT = 5;
const sf::Color COLORS[] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Cyan, sf::Color::Magenta };
const unsigned char MIN_ID = '0';
const unsigned char MAX_ID = '4';

Button::Button(const sf::Vector2f& pos, unsigned char buttonId, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , Interactable(pos, size)
    , m_color(COLORS[buttonId - MIN_ID])
{
    m_shape.setFillColor(m_color);
}


void Button::interact(GameObj& interactor)
{
    if (dynamic_cast<Player*>(&interactor)) {
        // Get all doors in the game
        std::vector<Door*> doors = Game::i().getAll<Door>();

        // If the door has the same color -> remove it
        for (Door* d : doors)
            if (d->getColor() == m_color)
                Game::i().removeObj(*d);

        // Remove the button
        Game::i().removeObj(*this);
    }
}


Button::Button(std::ifstream& in)
    : GameObj(in)
    , Entity(in)
    , Interactable(in)
{
    in.read((char*) &m_color, sizeof(m_color));
    m_shape.setFillColor(m_color);
}


void Button::serialize(std::ofstream& file) const
{
    unsigned char id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    Interactable::serialize(file);

    file.write((const char*) &m_color, sizeof(m_color));
}


unsigned char Button::getSaveId()
{
    return getMinId();
}


unsigned char Button::getMinId()
{
    return MIN_ID;
}


unsigned char Button::getMaxId()
{
    return MAX_ID;
}
