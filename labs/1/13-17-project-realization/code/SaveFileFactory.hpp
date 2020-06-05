#pragma once

#include "FileFactory.hpp"

class SaveFileFactory : public FileFactory
{
public:
    SaveFileFactory(std::ifstream& file);
    virtual GameObj* createObj() const override;
};
