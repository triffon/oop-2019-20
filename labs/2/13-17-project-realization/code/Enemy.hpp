#pragma once

#include "PhysicsObj.hpp"

/**
 * The abstract class for enemies
 */
class Enemy : public PhysicsObj
{
/// Implements the polymorphic BigFour
public:
    Enemy(const sf::Vector2f& pos, const sf::Vector2f& size);
    Enemy(const Enemy& other) = default;
    Enemy& operator=(const Enemy& other) = default;
    virtual ~Enemy() = default;

protected:
    /**
     * Calculates the basic AI movement changing m_hspd, without actually moving the enemy.
     */
    void basicAI();
};
