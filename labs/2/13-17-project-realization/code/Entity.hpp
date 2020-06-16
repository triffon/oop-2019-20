#pragma once

#include "GameObj.hpp"

/**
 * The abstract non-solid object class
 */
class Entity : virtual public GameObj
{
/// Implements the polymorphic BigFour
public:
    Entity(const sf::Vector2f& pos, const sf::Vector2f& size);
    Entity(const Entity& other) = default;
    Entity& operator=(const Entity& other) = default;
    virtual ~Entity() = default;

    /**
     * Constructs an enemy from the given binary file
     */
    Entity(std::ifstream& in);
};
