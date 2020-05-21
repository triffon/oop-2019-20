#pragma once

#include <SFML/Graphics.hpp>

/**
 * The base abstract class Object in the game's hierarchy
 */
class GameObj
{
/// Implements the polymorphic BigFour
public:
    GameObj(sf::Vector2f pos, sf::Vector2f size = { 0 , 0 });
    GameObj(const GameObj& other) = default;
    GameObj& operator=(const GameObj& other) = default;
    virtual ~GameObj() = default;

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const = 0;

    /**
     * Polymorphic draw method used to draw the object on the screen
     */
    virtual void draw() const = 0;

    /**
     * @returns The position of the object
     */
    sf::Vector2f getPosition() const { return m_position; }

    /**
     * @returns The size of the object
     */
    sf::Vector2f getSize()     const { return m_size; }

protected:
    // The position of the object
    sf::Vector2f m_position;

    // The size of the object
    sf::Vector2f m_size;
};
