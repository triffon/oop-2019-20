#include "Entity.hpp"

Entity::Entity(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
{}


Entity::Entity(std::ifstream& in)
    : GameObj(in)
{}
