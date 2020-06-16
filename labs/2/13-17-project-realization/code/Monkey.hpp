#pragma once

#include "Enemy.hpp"
#include "Game.hpp"

/**
 * Enemy type with a more complex AI
 */
class Monkey : public Enemy
{
/// Implements the polymorphic BigFour
public:
    Monkey(const sf::Vector2f& pos, const sf::Vector2f& size = { Game::BLOCK_SIZE * 0.75f , Game::BLOCK_SIZE * 0.75f });
    Monkey(const Monkey& other) = default;
    Monkey& operator=(const Monkey& other) = default;
    virtual ~Monkey() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) Monkey(*this); }

    /**
     * Polymorphic method that runs every frame used for AI
     */
    virtual void update() override;

    // TODO: Add serialize method and deserializing constructor
};
