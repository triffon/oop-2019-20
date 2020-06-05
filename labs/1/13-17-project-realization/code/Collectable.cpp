#include "Collectable.hpp"
#include "Game.hpp"

Collectable::Collectable(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Interactable(pos, size)
{}


Collectable::Collectable(std::ifstream& in)
    : Interactable(in)
{}


void Collectable::interact(GameObj&)
{
    Game::i().removeObj(*this);
}
