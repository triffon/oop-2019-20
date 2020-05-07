#pragma once

#include <array>
#include "Entity.hpp"
#include "Coord.hpp"

class GameEngine
{
private:
    static const int DEFAULT_WIDTH  = 10;
    static const int DEFAULT_HEIGHT = 6;

public:
    GameEngine();
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;
    ~GameEngine();
    void addEntity(Entity* e, size_t x, size_t y);

    void changePos(Coord pos, Coord offs);
    void move(Coord pos);
    void moveAll();
    void drawTerrain() const;

    void shoot(Coord pos, int dmg);

    void run();

private:
    std::array<std::array<Entity*, DEFAULT_WIDTH>, DEFAULT_HEIGHT> m_terrain;
};