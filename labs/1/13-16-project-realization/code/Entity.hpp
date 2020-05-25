#pragma once

#include "GameObj.hpp"

/**
 * The abstract non-solid object class
 */
class Entity : public GameObj
{
/// Implements the polymorphic BigFour
public:
    Entity(const sf::Vector2f& pos, const sf::Vector2f& size);
    Entity(const Entity& other) = default;
    Entity& operator=(const Entity& other) = default;
    virtual ~Entity() = default;
};
