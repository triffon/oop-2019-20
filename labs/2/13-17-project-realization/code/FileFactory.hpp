#pragma once

#include <fstream>
#include "Factory.hpp"

class FileFactory : public Factory
{
public:
    FileFactory(std::ifstream& file);

protected:
    std::ifstream& m_file;
};
