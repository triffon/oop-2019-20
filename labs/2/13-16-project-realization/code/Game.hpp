#pragma once

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include "GameObj.hpp"

/**
 * Singleton Game class that houses all of the game's internal logic
 */
class Game
{
private:
    /**
     * Singleton's default constructor
     */
    Game() = default;

public:
    /**
     * @returns A reference to the Singleton Game object
     */
    static Game& i();
    Game(Game const&) = delete;
    void operator=(Game const&) = delete;
    ~Game();

    /**
     * Initializes the game
     */
    void initGame(const sf::VideoMode& vm, const char* title);

    /**
     * Starts the game loop
     */
    void run();

    /**
     * Polls all kinds of user events
     */
    void pollEvents();

    /**
     * Updates all objects that can be updated
     */
    void updateAll();

    /**
     * Adds an object to the window to be rendered
     */
    void draw(const sf::Drawable& drawable);

    /**
     *  Draws all objects
     */
    void drawAll();

    /**
     * Adds a dynamically allocated polymorhic object to the game
     */
    void addObj(GameObj* obj);

    /**
     * @returns All objects of the template type that are
     * in collision with the specified collisionRect
     */
    template<typename T>
    std::vector<T*> checkCollision(const sf::Rect<float>& collisionRect) const;

    /**
     * @returns The window's size (excluding the border)
     */
    sf::Vector2u getWindowsSize() const { return m_window.getSize(); }

    /**
     * The game tiles' size
     */
    static const float BLOCK_SIZE;

private:
    // The type of the container used to store the game objects
    using GameObjContainer = std::vector<GameObj*>;

    // The container that stores all the game objects
    GameObjContainer m_objects;

    // The window all objects get drawn on
    sf::RenderWindow m_window;

    // Microseconds in one second
    static const int MICROS_IN_SEC;

    // Framerate at which the game runs
    static const int FPS;

    // The target time in microseconds between each frame
    static const int REFRESH_RATE;
};


template<typename T>
std::vector<T*> Game::checkCollision(const sf::Rect<float>& collisionRect) const
{
    // New: This method now returns a vector of all collided objects
    std::vector<T*> result;

    // Iterates through all game objects
    for (size_t i = 0; i < m_objects.size(); ++i) {

        // If an object is of the specified type
        if (T* obj = dynamic_cast<T*>(m_objects[i])) {

            // And if it's colliding -> add it to the result vector
            sf::Rect<float> objRect(obj->getPosition(), obj->getSize());
            if (collisionRect.intersects(objRect))
                result.push_back(obj);

        }

    }

    return result;
}
