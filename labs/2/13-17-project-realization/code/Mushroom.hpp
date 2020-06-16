#pragma once

#include "Enemy.hpp"
#include "Game.hpp"

/**
 * The basic enemy type
 */
class Mushroom : public Enemy
{
/// Implements the polymorphic BigFour
public:
    Mushroom(const sf::Vector2f& pos, const sf::Vector2f& size = { Game::BLOCK_SIZE , Game::BLOCK_SIZE });
    Mushroom(const Mushroom& other) = default;
    Mushroom& operator=(const Mushroom& other) = default;
    virtual ~Mushroom() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) Mushroom(*this); }

    /**
     * Polymorphic method that runs every frame used for AI
     */
    virtual void update() override;

    // TODO: Add serialize method and deserializing constructor
};
