#pragma once

#include "PhysicsObj.hpp"
#include "Game.hpp"

/**
 * The player object class
 */
class Player : public PhysicsObj
{
/// Implements the polymorphic BigFour
public:
    Player(sf::Vector2f pos, sf::Vector2f size = { Game::BLOCK_SIZE , Game::BLOCK_SIZE });
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;
    virtual ~Player() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new Player(*this); }

    /**
     * Polymorphic draw method used to draw the player on the screen
     */
    virtual void draw() const override;

    /**
     * Polymorphic method that runs every frame
     */
    virtual void update() override;

protected:
    // The shape that gets drawn on the screen
    sf::RectangleShape m_shape;
};