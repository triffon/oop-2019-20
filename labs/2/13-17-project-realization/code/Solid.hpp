#pragma once

#include "GameObj.hpp"

/**
 * The abstract solid object class
 */
class Solid : virtual public GameObj
{
/// Implements the polymorphic BigFour
public:
    Solid(const sf::Vector2f& pos, const sf::Vector2f& size);
    Solid(std::ifstream& in);
    Solid(const Solid& other) = default;
    Solid& operator=(const Solid& other) = default;
    virtual ~Solid() = default;
};
