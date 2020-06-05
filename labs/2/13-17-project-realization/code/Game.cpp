#include <cmath>
#include <iostream>
#include <fstream>
#include "Game.hpp"
#include "PhysicsObj.hpp"
#include "SaveFileFactory.hpp"


// The default refresh rate
const unsigned int DEFAULT_FPS  = 30;

// The default background color
const sf::Color DEFAULT_BGCOLOR = { 127, 127, 127, 255 };

// The game tiles' size
const float Game::BLOCK_SIZE    = 32;

// The default save file name
const char* SAVE_FILE = "prev_save.bin";


Game::Game()
    : m_bgColor(DEFAULT_BGCOLOR)
    , m_FPS(DEFAULT_FPS)
{}


Game::~Game()
{
    deleteGameObjects();
}


void Game::initGame(const sf::VideoMode& vm, const char* title)
{
    // Create a window with the specified arguments
    m_window.create(vm, title);

    // Changed to SFML's framerate instead of our implementation
    m_window.setFramerateLimit(m_FPS);
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
        // Clear the window
        m_window.clear(m_bgColor);

        // Poll user events
        pollEvents();

        // Update all objects in the game
        updateAll();

        // Add all objects to the window
        drawAll();

        // Render the window
        m_window.display();
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        std::cout << "P pressed" << std::endl;
        // Save the game
        createSaveFile();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        std::cout << "L pressed" << std::endl;
        loadSaveFile();
        // Load the previous save
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


void Game::setFPS(unsigned int FPS)
{
    m_FPS = FPS;
    if (m_window.isOpen())
        m_window.setFramerateLimit(m_FPS);
}


void Game::removeObj(const GameObj& obj)
{
    // Search the target object, delete and erase it from the vector
    for (size_t i = 0; i < m_objects.size(); i++) {
        // Compare the target's address and the stored pointer (address)
        if (&obj == m_objects[i]) {
            delete m_objects[i];
            m_objects.erase(m_objects.begin() + i);
            return;
        }
    }
}


void Game::createSaveFile() const
{
    std::ofstream file(SAVE_FILE, std::ios::binary);
    if (!file) {
        std::cout << "Couldn't save the game!" << std::endl;
        return;
    }

    for (size_t i = 0; i < m_objects.size(); i++)
        m_objects[i]->seriallize(file);

    file.close();
}


void Game::loadSaveFile()
{
    std::ifstream file(SAVE_FILE, std::ios::binary);
    if (!file) {
        std::cout << "Couldn't load the game!" << std::endl;
        return;
    }

    deleteGameObjects();

    SaveFileFactory fact(file);
    while (GameObj* obj = fact.createObj())
        m_objects.push_back(obj);

    file.close();
}


void Game::deleteGameObjects()
{
    // Iterate through the game's object container
    // and delete them, because they are polymorphic
    for (size_t i = 0; i < m_objects.size(); ++i)
        delete m_objects[i];
    
    m_objects.clear();
}
