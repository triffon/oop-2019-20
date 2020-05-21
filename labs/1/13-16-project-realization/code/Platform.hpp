#pragma once

#include "Solid.hpp"

/**
 * A solid platform represented by a rectangle
 */
class Platform : public Solid
{
/// Implements the polymorphic BigFour
public:
    Platform(sf::Vector2f pos, sf::Vector2f size = { 0 , 0 });
    Platform(const Platform& other) = default;
    Platform& operator=(const Platform& other) = default;
    virtual ~Platform() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new Platform(*this); }

    /**
     * Polymorphic draw method used to draw the platform on the screen
     */
    virtual void draw() const override;

protected:
    // The rectangle shaped that gets drawn on the screen
    sf::RectangleShape m_shape;
};
