#pragma once

#include "Solid.hpp"
#include "Game.hpp"

/**
 * Class representing an unlockable colored door
 */
class Door : public Solid
{
/// Implements the polymorphic BigFour
public:
    Door(const sf::Vector2f& pos, unsigned char doorId = getSaveId(), const sf::Vector2f& size = { Game::BLOCK_SIZE, Game::BLOCK_SIZE });
    Door(const Door& other) = default;
    Door& operator=(const Door& other) = default;
    virtual ~Door() = default;

    /**
     * Constructs a door from the given binary file
     */
    Door(std::ifstream& in);

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) Door(*this); }

    /**
     * @returns The door's color
     */
    sf::Color getColor() const { return m_color; }

    static unsigned char getMinId();
    static unsigned char getMaxId();
    static unsigned char getSaveId();

    /**
     * Serializes the object to a binary file
     */
    virtual void serialize(std::ofstream& file) const override;

private:
    sf::Color m_color;
};
