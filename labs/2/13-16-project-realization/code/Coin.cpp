#include "Coin.hpp"
#include "Player.hpp"

const size_t Coin::REWARD = 10;


Coin::Coin(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , Collectable(pos, size)
{
    m_shape.setFillColor(sf::Color::Yellow);
}


void Coin::interact(GameObj& interactor)
{
    if (Player* p = dynamic_cast<Player*>(&interactor)) {
        p->addScore(REWARD);
        Collectable::interact(interactor);
    }
}
