#pragma once

#include "Entity.hpp"

/**
 * Abstract class representing interactable game objects
 */
class Interactable : public Entity
{
// Implements the polymorphic BigFour
public:
    Interactable(const sf::Vector2f& pos, const sf::Vector2f& size);
    Interactable(const Interactable& other) = default;
    Interactable& operator=(const Interactable& other) = default;
    virtual ~Interactable() = default;

    // TODO: Add interact(...) method
};