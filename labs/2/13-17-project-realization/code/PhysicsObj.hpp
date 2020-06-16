#pragma once

#include "Entity.hpp"

/**
 * The base abstract class object of an object using Physics
 */
class PhysicsObj : virtual public Entity
{
/// Implements the polymorphic BigFour
public:
    PhysicsObj(const sf::Vector2f& pos, const sf::Vector2f& size, float gravity = 0.5);
    PhysicsObj(const PhysicsObj& other) = default;
    PhysicsObj& operator=(const PhysicsObj& other) = default;
    virtual ~PhysicsObj() = default;

    /**
     * Constructs a physics object from the given binary file
     */
    PhysicsObj(std::ifstream& in);

    /**
     * Polymorphic method that runs every frame and applies gravity to m_vspd.
     * Note: This method doesn't actually move() the object, rather it just calculates gravity.
     */
    virtual void update();

    /**
     * Change the object's gravity (must be greater than 0)
     */
    void setGravity(float gravity) { m_grav = gravity > 0 ? gravity : 0; }

    /**
     * @returns the object's current horizontal speed
     */
    float getHspd() const { return m_hspd; }

    /**
     * @returns the object's current vertical speed
     */
    float getVspd() const { return m_vspd; }

    /**
     * Serializes the object to a binary file
     */
    virtual void serialize(std::ofstream& file) const override;

protected:
    // Gravity acceleration
    float m_grav;

    // The object's horizontal speed
    float m_hspd;

    // The object's vertical speed
    float m_vspd;

    // The object is on the ground
    bool m_grounded;
};
