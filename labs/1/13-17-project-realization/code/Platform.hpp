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
    Platform(const Platform& other) = default;
    Platform& operator=(const Platform& other) = default;
    virtual ~Platform() = default;

    /**
     * Constructs a platform from the given binary file
     */
    Platform(std::ifstream& in);

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) Platform(*this); }

    /**
     * Platform's ID used for savefiles
     */
    static unsigned char getSaveId();

    /**
     * Serializes the object to a binary file
     */
    virtual void serialize(std::ofstream& file) const override;
};
