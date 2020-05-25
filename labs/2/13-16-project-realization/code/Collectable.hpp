#pragma once

#include "Interactable.hpp"

/**
 * Abstract class representing collectable game objects
 */
class Collectable : public Interactable
{
/// Implements the polymorphic BigFour
public:
    Collectable(const sf::Vector2f& pos, const sf::Vector2f& size);
    Collectable(const Collectable& other) = default;
    Collectable& operator=(const Collectable& other) = default;
    virtual ~Collectable() = default;

    // TODO: Implement the default interact(...) method - destroying self
};
