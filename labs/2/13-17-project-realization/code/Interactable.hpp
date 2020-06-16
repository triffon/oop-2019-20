#pragma once

#include "Entity.hpp"

/**
 * Abstract class representing interactable game objects
 */
class Interactable : virtual public Entity
{
// Implements the polymorphic BigFour
public:
    Interactable(const sf::Vector2f& pos, const sf::Vector2f& size);
    Interactable(const Interactable& other) = default;
    Interactable& operator=(const Interactable& other) = default;
    virtual ~Interactable() = default;

    /**
     * Constructs an interactable object from the given binary file
     */
    Interactable(std::ifstream& in);

    /**
     * Pure virtual method that's called when an object interacts with this object.
     * @param interactor is the object that is interacting with the current object
     */
    virtual void interact(GameObj& interactor) = 0;
};
