#pragma once

#include "PhysicsObj.hpp"
#include "Game.hpp"
#include "Solid.hpp"

/**
 * The player object class
 */
class Player : public PhysicsObj, public Solid
{
/// Implements the polymorphic BigFour
public:
    Player(const sf::Vector2f& pos, const sf::Vector2f& size = { Game::BLOCK_SIZE , Game::BLOCK_SIZE });
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;
    virtual ~Player() = default;

    /**
     * Constructs a player from the given binary file
     */
    Player(std::ifstream& in);

    /**
     * Polymorphic clone method
     * @returns A pointer to a dynamically allocated polymorhic game object
     */
    virtual GameObj* clone() const override { return new (std::nothrow) Player(*this); }

    /**
     * Polymorphic method that runs every frame
     */
    virtual void update() override;

    /**
     * Draws the score on screen
     */
    virtual void drawGUI() const override;

    /**
     * Adds points to the player's score
     * @param score is the amount of points to be added
     */
    void addScore(size_t points);

    /**
     * Serializes the object to a binary file
     */
    virtual void serialize(std::ofstream& file) const override;

    /**
     * Player's ID used for savefiles
     */
    static unsigned char getSaveId();

private:
    // The horizontal speed acceleration
    float m_acc;

    // The maximal horizontal speed
    float m_maxhspd;

    // The jump force
    float m_jumpforce;

    // The horizontal drag
    float m_hdrag;

    // Player's score
    size_t m_score;

private:
    // Movement script
    void calcHspd();

    // Horizontal collision script
    void hcollide();

    // Jump script
    void calcVspd();

    // Vertical collision script
    void vcollide();

    // Method to check for collectables
    void activateInteractables();
};
