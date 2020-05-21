#pragma once

#include "GameObj.hpp"

/**
 * The base solid object class
 */
class Solid : public GameObj
{
/// Implements the polymorphic BigFour
public:
    Solid(sf::Vector2f pos, sf::Vector2f size = { 0 , 0 });
    Solid(const Solid& other) = default;
    Solid& operator=(const Solid& other) = default;
    virtual ~Solid() = default;
};
