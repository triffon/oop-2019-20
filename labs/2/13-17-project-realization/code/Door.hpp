#pragma once

#include "Solid.hpp"

/**
 * Class representing an unlockable colored door
 */
class Door : public Solid
{
/// Implements the polymorphic BigFour
public:
    Door(const sf::Vector2f& pos, const sf::Vector2f& size);
    Door(const Door& other) = default;
    Door& operator=(const Door& other) = default;
    virtual ~Door() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new Door(*this); }

    // TODO: Implement door lock/unlocking
};
