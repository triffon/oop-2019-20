#pragma once

#include <string>
#include "FileFactory.hpp"

class LevelFactory : public FileFactory
{
public:
    /**
     * Creates a level factory tied to a level file
     */
    LevelFactory(std::ifstream& file);

    /**
     * @returns A dynamically allocated polymorphic game object read from the level file
     */
    virtual GameObj* createObj() override;

private:
    size_t m_currRow;
    size_t m_currCol;
    std::string m_currLine;
};
