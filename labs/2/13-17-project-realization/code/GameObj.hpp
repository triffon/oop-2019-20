#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>

/**
 * The base abstract class Object in the game's hierarchy
 */
class GameObj
{
/// Implements the polymorphic BigFour
public:
    GameObj(const sf::Vector2f& pos, const sf::Vector2f& size);
    GameObj(const GameObj& other) = default;
    GameObj& operator=(const GameObj& other) = default;
    virtual ~GameObj() = default;

    /**
     * Constructs a game object from the given binary file
     */
    GameObj(std::ifstream& in);

    /**
     * Pure virtual clone method
     * @returns A pointer to a dynamically allocated polymorphic game object
     */
    virtual GameObj* clone() const = 0;

    /**
     * Polymorphic draw method used to draw the object on the screen
     */
    virtual void draw() const;

    /**
     * Polymorphic draw method used to draw the object's GUI
     */
    virtual void drawGUI() const;

    /**
     * @returns The position of the object
     */
    sf::Vector2f getPosition() const { return m_shape.getPosition(); }

    /**
     * Sets the position of the object
     */
    void setPosition(const sf::Vector2f& pos) { m_shape.setPosition(pos); }

    /**
     * Moves the object by the given offset
     */
    void move(const sf::Vector2f& offset) { m_shape.move(offset); }

    /**
     * @returns The size of the object
     */
    sf::Vector2f getSize() const { return m_shape.getSize(); }

    /**
     * Save the current object to a binary file
     */
    virtual void serialize(std::ofstream& file) const;

protected:
    // Moved the m_shape to the base class GameObj
    // The rectangle of the object containing its position and size
    // it's also used to render the object to the screen via draw()
    sf::RectangleShape m_shape;
};
