#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Platform.hpp"
#include "Player.hpp"

int main()
{
    // Temporary game objects to test while writing the code

    Game::i().initGame(sf::VideoMode(960, 540), "Platformer");

    Game::i().addObj (
        new Platform (
            sf::Vector2f( Game::BLOCK_SIZE, Game::i().getWindowsSize().y - Game::BLOCK_SIZE ),
            sf::Vector2f( Game::i().getWindowsSize().x - 2 * Game::BLOCK_SIZE, Game::BLOCK_SIZE )
        )
    );

    Game::i().addObj( new Platform({ 200, 400 }, { 200, Game::BLOCK_SIZE }) );
    Game::i().addObj( new Platform({ 550, 300 }, { 300, Game::BLOCK_SIZE }) );

    Game::i().addObj( new Player({ Game::i().getWindowsSize().x / 2, 0 }) );

    Game::i().run();

    return 0;
}
