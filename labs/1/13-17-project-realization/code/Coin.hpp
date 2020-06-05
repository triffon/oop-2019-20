#pragma once

#include "Collectable.hpp"
#include "Game.hpp"

/**
 * Class representing a coin that can be collected by the player
 */
class Coin : public Collectable
{
/// Implements the polymorphic BigFour
public:
    Coin(const sf::Vector2f& pos, const sf::Vector2f& size = { Game::BLOCK_SIZE * 0.5f , Game::BLOCK_SIZE * 0.5f });
    Coin(const Coin& other) = default;
    Coin& operator=(const Coin& other) = default;
    virtual ~Coin() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new Coin(*this); }

    /**
     * Method that's called when an object interacts with this object
     * @param interactor is the object that is interacting with the current object
     */
    virtual void interact(GameObj& interactor) override;

    // Amount of points awarded
    static const size_t REWARD;
};
