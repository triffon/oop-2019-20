#include <cmath>
#include <iostream>
#include <fstream>
#include "Game.hpp"
#include "PhysicsObj.hpp"
#include "SaveFileFactory.hpp"
#include "LevelFactory.hpp"
#include "Player.hpp"

// The default refresh rate
const unsigned int DEFAULT_FPS  = 30;

// The default background color
const sf::Color DEFAULT_BGCOLOR = { 127, 127, 127, 255 };

// The game tiles' size
const float Game::BLOCK_SIZE    = 32;

// The default save file name
const char* SAVE_FILE = "prev_save.bin";

// The default font file
const char* DEFAULT_FONT = "Montserrat-Regular.ttf";

// The default font outline thickness
const size_t DEFAULT_FONT_OUTLINE = 1;

// Info message
const char* INFO_MSG = "Use WASD + Space to move.\n"
                       "Press 'P' to save the game.\n"
                       "Press 'L' to load the last save.\n"
                       "Press '1' to load level 1.";

// Info message position
const sf::Vector2f INFO_MSG_POS = { 10, 40 };

// Info message size
const size_t INFO_MSG_SIZE = 14;

// View Y offset factor
const float VIEW_Y_OFFSET_FACTOR = 0.15f;


Game::Game()
    : m_viewFollow(nullptr)
    , m_bgColor(DEFAULT_BGCOLOR)
    , m_FPS(DEFAULT_FPS)
{
    if (!m_defaultFont.loadFromFile(DEFAULT_FONT))
        std::cout << "Couldn't load the default font: " << DEFAULT_FONT << "!" << std::endl;
}


Game::~Game()
{
    deleteGameObjects();
}


void Game::initGame(const sf::VideoMode& vm, const char* title)
{
    // Create a window with the specified arguments
    m_window.create(vm, title);

    // Create the view of the game
    m_view = sf::View({ vm.width / 2.0f, vm.height / 2.0f }, { (float)vm.width, (float)vm.height });

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

        // Add all GUI elements to the window
        drawAllGUI();

        // Set view
        if (m_viewFollow) {
            sf::Vector2f fPos = m_viewFollow->getPosition();
            fPos += m_viewFollow->getSize() * 0.5f; // Center on object
            fPos.y -= m_window.getSize().y * VIEW_Y_OFFSET_FACTOR;
            m_view.setCenter(fPos);
        }
        m_window.setView(m_view);

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
        createSaveFile();
        std::cout << "Game saved!" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        loadSaveFile();
        std::cout << "Game loaded!" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        loadLevel(1);
        std::cout << "Level 1 loaded!" << std::endl;
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


void Game::drawAllGUI()
{
    // Iterate through all game objects and draw them
    for (size_t i = 0; i < m_objects.size(); ++i)
        m_objects[i]->drawGUI();

    drawGUIText(INFO_MSG_POS, INFO_MSG, INFO_MSG_SIZE, sf::Color::White, sf::Color::Black);
}


void Game::drawText(const sf::Vector2f& pos, const std::string& text, size_t textSize, sf::Color textColor, sf::Color outlineColor)
{
    sf::Text t;
    t.setPosition(pos);
    t.setString(text);
    t.setFont(m_defaultFont);
    t.setFillColor(textColor);
    t.setOutlineColor(outlineColor);
    t.setOutlineThickness(DEFAULT_FONT_OUTLINE);
    t.setCharacterSize(textSize);
    m_window.draw(t);
}


void Game::drawGUIText(const sf::Vector2f& pos, const std::string& text, size_t textSize, sf::Color textColor, sf::Color outlineColor) 
{
    drawText(pos + m_view.getCenter() - m_view.getSize() / 2.0f, text, textSize, textColor, outlineColor);
}


void Game::addObj(GameObj* obj)
{
    // Just adds the polymorphic object
    // to our GameObject container
    m_objects.push_back(obj);

    // Saving a pointer to the player object
    // as the camera follow object
    if (dynamic_cast<Player*>(obj))
        m_viewFollow = obj;
}


void Game::setFPS(unsigned int FPS)
{
    m_FPS = FPS;
    if (m_window.isOpen())
        m_window.setFramerateLimit(m_FPS);
}


void Game::removeObj(const GameObj& obj)
{
    for (size_t i = 0; i < m_objects.size(); i++) {
        // Compare the target's address and the stored pointer (address)
        if (&obj == m_objects[i]) {
            // If we're about to remove the viewFollow object
            // set the quick access 
            if (m_objects[i] == m_viewFollow)
                m_viewFollow = nullptr;

            // Delete the polymorphic object
            delete m_objects[i];

            // Erase it from the vector
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
        m_objects[i]->serialize(file);

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
        addObj(obj);

    file.close();
}


void Game::loadLevel(size_t level)
{
    std::string fileName = "level" + std::to_string(level);
    std::ifstream file(fileName);
    if (!file) {
        std::cout << "Couldn't load " << fileName << "!" << std::endl;
        return;
    }

    deleteGameObjects();

    LevelFactory fac(file);
    while (GameObj* obj = fac.createObj())
        addObj(obj);

    file.close();
}

void Game::deleteGameObjects()
{
    // Reset the view follow pointer
    m_viewFollow = nullptr;

    // Iterate through the game's object container
    // and delete them, because they are polymorphic
    for (size_t i = 0; i < m_objects.size(); ++i)
        delete m_objects[i];

    // Clear the vector
    m_objects.clear();
}
