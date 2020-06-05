#pragma once

#include "GameObj.hpp"

class Factory
{
public:
    virtual GameObj* createObj() const = 0;
    virtual ~Factory() = default;
};
