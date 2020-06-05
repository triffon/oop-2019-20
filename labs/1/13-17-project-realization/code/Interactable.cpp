#include "Interactable.hpp"

Interactable::Interactable(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Entity(pos, size)
{}


Interactable::Interactable(std::ifstream& in)
    : Entity(in)
{}
