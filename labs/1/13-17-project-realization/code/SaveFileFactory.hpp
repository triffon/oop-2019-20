#pragma once

#include "FileFactory.hpp"

class SaveFileFactory : public FileFactory
{
public:
    /**
     * Creates a save file factory tied to a binary save file
     */
    SaveFileFactory(std::ifstream& file);

    /**
     * @returns A dynamically allocated polymorphic game object read from the save file
     */
    virtual GameObj* createObj() override;
};
