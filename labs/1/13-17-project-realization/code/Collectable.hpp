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

    /**
     * Constructs a collectable object from the given binary file
     */
    Collectable(std::ifstream& in);

    /**
     * Polymorphic method that's called when an object interacts with this object.
     * By default this method removes the current collectable object from the game
     * using the Game::i().removeObj(*this) method.
     * @param interactor is the object that is interacting with the current object
     */
    virtual void interact(GameObj&) override;

    /**
     * By default calls the interact(interactor) method
     * @param interactor is the object that is collecting the current object
     */
    void collect(GameObj& interactor) { interact(interactor); }
};
