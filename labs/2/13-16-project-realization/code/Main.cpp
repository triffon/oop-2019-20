#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "Crate.hpp"

int main()
{
    // Temporary game objects to test while writing the code

    Game::i().initGame(sf::VideoMode(960, 544), "Platformer");

    Game::i().addObj (
        new Platform (
            sf::Vector2f( Game::BLOCK_SIZE, Game::i().getWindowsSize().y - Game::BLOCK_SIZE ),
            sf::Vector2f( Game::i().getWindowsSize().x - 2 * Game::BLOCK_SIZE, Game::BLOCK_SIZE )
        )
    );

    Game::i().addObj( new Platform({ 200.0f, 400.0f }, { 200.0f, Game::BLOCK_SIZE }) );
    Game::i().addObj( new Platform({ 550.0f, 300.0f }, { 300.0f, Game::BLOCK_SIZE }) );

    Game::i().addObj( new Platform({ 200.0f, 400.0f }, { Game::BLOCK_SIZE, 140.0f }) );

    Game::i().addObj( new Player({ Game::i().getWindowsSize().x / 2.0f, 0.0f }) );

    Game::i().addObj( new Crate({ 15 * Game::BLOCK_SIZE, 14 * Game::BLOCK_SIZE }) );

    Game::i().run();

    return 0;
}
