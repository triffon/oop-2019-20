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

    /**
     * Constructs a pushable object from the given binary file
     */
    Pushable(std::ifstream& in);

    /**
     * Virtual method that's called when an object interacts with this object.
     * @param interactor is the object that is interacting with the current object
     */
    virtual void interact(GameObj& interactor) override;
};
