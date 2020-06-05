#include "Solid.hpp"

Solid::Solid(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
{}


Solid::Solid(std::ifstream& in)
    : GameObj(in)
{}
