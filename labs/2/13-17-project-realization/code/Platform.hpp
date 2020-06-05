#pragma once

#include "Solid.hpp"

/**
 * A solid platform represented by a rectangle
 */
class Platform : public Solid
{
/// Implements the polymorphic BigFour
public:
    Platform(const sf::Vector2f& pos, const sf::Vector2f& size);
    Platform(std::ifstream& in);
    Platform(const Platform& other) = default;
    Platform& operator=(const Platform& other) = default;
    virtual ~Platform() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new Platform(*this); }

    /**
     * Platform's ID used for savefiles
     */
    static size_t getSaveId();

    /**
     * Save the current object to a binary file
     */
    virtual void seriallize(std::ofstream& file) const override;
};
