#include "Coin.hpp"
#include "Player.hpp"

const size_t Coin::REWARD = 10;
const unsigned char ID    = 'o';
const sf::Color DEFAULT_COLOR = sf::Color::Yellow;


Coin::Coin(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , Collectable(pos, size)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


Coin::Coin(std::ifstream& in)
    : GameObj(in)
    , Entity(in)
    , Collectable(in)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


void Coin::interact(GameObj& interactor)
{
    if (Player* p = dynamic_cast<Player*>(&interactor)) {
        p->addScore(REWARD);
        Collectable::interact(interactor);
    }
}


unsigned char Coin::getSaveId()
{
    return ID;
}


void Coin::serialize(std::ofstream& file) const
{
    unsigned char id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    Collectable::serialize(file);
}
