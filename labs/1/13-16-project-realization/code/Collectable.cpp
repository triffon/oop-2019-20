#include "Collectable.hpp"
#include "Game.hpp"

Collectable::Collectable(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Interactable(pos, size)
{}


void Collectable::interact(GameObj& interactor)
{
    Game::i().removeObj(*this);
}
