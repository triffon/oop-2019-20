#pragma once

#include "Entity.hpp"

/**
 * The base abstract class object of an object using Physics
 */
class PhysicsObj : public Entity
{
/// Implements the polymorphic BigFour
public:
    PhysicsObj(sf::Vector2f pos, sf::Vector2f size = { 0 , 0 }, float gravity = 0.5);
    PhysicsObj(const PhysicsObj& other) = default;
    PhysicsObj& operator=(const PhysicsObj& other) = default;
    virtual ~PhysicsObj() = default;

    /**
     * Polymorphic method that runs every frame and applies gravity
     */
    virtual void update();

    /**
     * Change the object's gravity (must be greater than 0)
     */
    void setGravity(float gravity) { m_grav = gravity > 0 ? gravity : 0; }

protected:
    // Gravity acceleration
    float m_grav;

    // The object's horizontal speed
    float m_hspd;

    // The object's vertical speed
    float m_vspd;

    // The object is on the ground
    bool  m_grounded;
};