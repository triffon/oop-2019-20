#pragma once

#include "GameObj.hpp"

class Factory
{
public:
    /**
     * The pure virtual creatObj method every factory should implement
     */
    virtual GameObj* createObj() = 0;

    virtual ~Factory() = default;
};
