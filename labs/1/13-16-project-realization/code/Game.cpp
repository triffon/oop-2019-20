#include <thread>
#include "Game.hpp"
#include "PhysicsObj.hpp"


// Microseconds in one second
const int   Game::MICROS_IN_SEC = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::seconds(1)).count();

// Framerate at which the game runs
const int   Game::FPS           = 60;

// The target time in microseconds between each frame
const int   Game::REFRESH_RATE  = MICROS_IN_SEC / FPS;

// The game tiles' size
const float Game::BLOCK_SIZE    = 32;


Game::~Game()
{
    // Iterate through the game's object container
    // and delete them, because they are polymorphic
    for (size_t i = 0; i < m_objects.size(); ++i)
        delete m_objects[i];
}


void Game::initGame(const sf::VideoMode& vm, const char* title)
{
    // Create a window with the specified arguments
    m_window.create(vm, title);
}


Game& Game::i()
{
    // Singleton object creation
    static Game instance;
    return instance;
}


void Game::run()
{
    // While the window is open
    while (m_window.isOpen())
    {
        // Get the time at which the frame starts
        std::chrono::time_point start = std::chrono::high_resolution_clock::now();

        // Clear the window
        m_window.clear(sf::Color(128, 128, 128, 255));

        // Poll user events
        pollEvents();

        // Update all objects in the game
        updateAll();

        // Add all objects to the window
        drawAll();

        // Render the window
        m_window.display();

        // Get the time at which the frame has finished rendering
        std::chrono::time_point end = std::chrono::high_resolution_clock::now();
        int duration = REFRESH_RATE - std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // Make the thread sleep for a calculated amount of time to make
        // sure the game runs at approximately the specified FPS
        if (duration > 0)
            std::this_thread::sleep_for(std::chrono::microseconds(duration));
    }
}


void Game::pollEvents()
{
    // Iterate through all the window events
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // Close the window if the event is
        // "Window's close button is pressed"
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}


void Game::updateAll()
{
    // Iterate through the game objects and
    // updated them if they can be udpated
    for (size_t i = 0; i < m_objects.size(); ++i)
        if (PhysicsObj* po = dynamic_cast<PhysicsObj*>(m_objects[i]))
            po->update();
}


void Game::draw(const sf::Drawable& drawable)
{
    // Call the window's draw method
    m_window.draw(drawable);
}


void Game::drawAll()
{
    // Iterate through all game objects and draw them
    for (size_t i = 0; i < m_objects.size(); ++i)
        m_objects[i]->draw();
}

void Game::addObj(GameObj* obj)
{
    // Just adds the polymorphic object
    // to our GameObject container
    m_objects.push_back(obj);
}
