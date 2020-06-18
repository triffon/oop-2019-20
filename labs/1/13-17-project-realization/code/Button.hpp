#pragma once

#include "Interactable.hpp"
#include "Game.hpp"

class Button : public Interactable
{
// Implements the polymorphic BigFour
public:
    Button(const sf::Vector2f& pos, unsigned char buttonId = 0, const sf::Vector2f& size = { Game::BLOCK_SIZE * 0.75f , Game::BLOCK_SIZE * 0.75f });
    Button(const Button& other) = default;
    Button& operator=(const Button& other) = default;
    virtual ~Button() = default;

    /**
     * Constructs a button from the given binary file
     */
    Button(std::ifstream& in);

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) Button(*this); };

    /**
     * Method that's called when an object interacts with this object
     * @param interactor is the object that is interacting with the current object
     */
    virtual void interact(GameObj& interactor) override;

    /**
     * Serializes the object to a binary file
     */
    virtual void serialize(std::ofstream& file) const override;

    static unsigned char getSaveId();
    static unsigned char getMinId();
    static unsigned char getMaxId();

private:
    sf::Color m_color;
};
