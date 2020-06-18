#include "LevelFactory.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Crate.hpp"
#include "Coin.hpp"
#include "Button.hpp"
#include "Door.hpp"

LevelFactory::LevelFactory(std::ifstream& file)
    : FileFactory(file)
    , m_currRow(-1)
    , m_currCol(0)
{}


GameObj* LevelFactory::createObj()
{
    for (;;) {
        if (m_currCol >= m_currLine.length()) {
            if (m_file.eof())
                return nullptr;

            m_currCol = 0;
            ++m_currRow;

            do {
                std::getline(m_file, m_currLine);
            } while (!m_file.eof() && m_currLine[0] == '#');
        }

        unsigned char id = m_currLine[m_currCol];
        float currX = m_currCol * Game::BLOCK_SIZE;
        float currY = m_currRow * Game::BLOCK_SIZE;
        ++m_currCol;

        if (id == Player::getSaveId())
            return new (std::nothrow) Player({ currX, currY });

        if (id == Platform::getSaveId())
            return new (std::nothrow) Platform({ currX, currY }, { Game::BLOCK_SIZE, Game::BLOCK_SIZE });

        if (id == Crate::getSaveId())
            return new (std::nothrow) Crate({ currX, currY });

        if (id == Coin::getSaveId())
            return new (std::nothrow) Coin({ currX, currY });

        if (id >= Button::getMinId() && id <= Button::getMaxId())
            return new (std::nothrow) Button({ currX, currY }, id);

        if (id >= Door::getMinId() && id <= Door::getMaxId())
            return new (std::nothrow) Door({ currX, currY }, id);
    }
}

