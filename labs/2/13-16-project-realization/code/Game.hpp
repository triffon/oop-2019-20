#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "GameObj.hpp"

enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

/**
 * Singleton Game class that houses all of the game's internal logic
 */
class Game
{
private:
    /**
     * Singleton's default constructor
     */
    Game();

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
     * Sets the window's background color
     */
    void setWindowBgColor(const sf::Color& bgColor) { m_bgColor = bgColor; }

    /**
     * Sets the games refresh rate
     */
    void setFPS(unsigned int FPS);

    /**
     * The game tiles' size
     */
    static const float BLOCK_SIZE;

    /**
     * @returns The closest object of the given vector in the given direction
     */
    template<typename T>
    static T* getClosest(const std::vector<T*> objects, Direction dir);

private:
    // The type of the container used to store the game objects
    using GameObjContainer = std::vector<GameObj*>;

    // The container that stores all the game objects
    GameObjContainer m_objects;

    // The window all objects get drawn on
    sf::RenderWindow m_window;

    // New: The background color of the window
    sf::Color m_bgColor;

    // Framerate at which the game runs
    unsigned int m_FPS;

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


template<typename T>
T* Game::getClosest(const std::vector<T*> objects, Direction dir)
{
    // New: Method used in collisions
    if (objects.empty())
        return nullptr;

    // std::function can be thought of as something similar to "pointer to a function",
    // even though it's quite a bit more complex
    std::function<bool(const T*, const T*)> comparator;

    // Select the correct comparator function
    switch (dir)
    {
    case Direction::DOWN:
        comparator = [](const T* obj1, const T* obj2) { return obj1->getPosition().y < obj2->getPosition().y; };
        break;
    case Direction::UP:
        comparator = [](const T* obj1, const T* obj2) { return obj1->getPosition().y > obj2->getPosition().y; };
        break;
    case Direction::RIGHT:
        comparator = [](const T* obj1, const T* obj2) { return obj1->getPosition().x < obj2->getPosition().x; };
        break;
    case Direction::LEFT:
        comparator = [](const T* obj1, const T* obj2) { return obj1->getPosition().x > obj2->getPosition().x; };
        break;
    }

    // STL function that returns an iterator to the minimal element using a given function to compare
    return *std::min_element(objects.begin(), objects.end(), comparator);
}
