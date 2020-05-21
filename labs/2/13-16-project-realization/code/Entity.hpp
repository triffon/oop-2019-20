#pragma once

#include "GameObj.hpp"

/**
 * The base abstract non-solid object class
 */
class Entity : public GameObj
{
/// Implements the polymorphic BigFour
public:
    Entity(sf::Vector2f pos, sf::Vector2f size = { 0 , 0 });
    Entity(const Entity& other) = default;
    Entity& operator=(const Entity& other) = default;
    virtual ~Entity() = default;
};