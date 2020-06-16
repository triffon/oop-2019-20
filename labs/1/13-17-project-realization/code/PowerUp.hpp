#pragma once

#include "Collectable.hpp"
#include "Game.hpp"

/**
 * Class representing a power-up that can be collected by the player
 */
class PowerUp : public Collectable
{
/// Implements the polymorphic BigFour
public:
    PowerUp(const sf::Vector2f& pos, const sf::Vector2f& size = { Game::BLOCK_SIZE * 0.75f , Game::BLOCK_SIZE * 0.75f });
    PowerUp(const PowerUp& other) = default;
    PowerUp& operator=(const PowerUp& other) = default;
    virtual ~PowerUp() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) PowerUp(*this); }

    // TODO: Implement collecting power-ups
    // TODO: Add serialize method and deserializing constructor
};
