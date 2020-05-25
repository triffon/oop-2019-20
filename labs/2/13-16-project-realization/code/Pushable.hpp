#pragma once

#include "Interactable.hpp"

/**
 * Abstract class representing pushable game objects
 */
class Pushable : public Interactable
{
/// Implements the polymorphic BigFour
public:
    Pushable(const sf::Vector2f& pos, const sf::Vector2f& size);
    Pushable(const Pushable& other) = default;
    Pushable& operator=(const Pushable& other) = default;
    virtual ~Pushable() = default;

    // TODO: Override and implement interact(...)
};
