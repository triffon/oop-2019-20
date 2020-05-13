#include <iostream>
#include <thread>
#include <chrono>
#include "GameEngine.hpp"
#include "Unit.hpp"
#include "IShootable.hpp"


GameEngine::GameEngine()
{
    for (size_t i = 0; i < m_terrain.size(); i++)
        for (size_t j = 0; j < m_terrain[i].size(); j++)
            m_terrain[i][j] = new Entity;
}


GameEngine::~GameEngine()
{
    for (size_t i = 0; i < m_terrain.size(); i++)
        for (size_t j = 0; j < m_terrain[i].size(); j++)
            delete m_terrain[i][j];
}


void GameEngine::addEntity(Entity* e, size_t x, size_t y)
{
    if (y < m_terrain.size() && x < m_terrain[y].size()) {
        delete m_terrain[y][x];
        m_terrain[y][x] = e;
    }
}


void GameEngine::changePos(Coord pos, Coord offs)
{
    size_t newX = pos.x + offs.x;
    size_t newY = pos.y + offs.y;

    if (newX >= m_terrain[0].size())
        newX = pos.x;

    if (newY >= m_terrain.size())
        newY = pos.y;

    if (typeid(*m_terrain[newY][newX]) == typeid(Entity))
        std::swap(m_terrain[pos.y][pos.x], m_terrain[newY][newX]);
}


void GameEngine::move(Coord pos)
{
    Unit* u = dynamic_cast<Unit*>(m_terrain[pos.y][pos.x]);
    if (u)
        changePos(pos, u->move());
}


void GameEngine::moveAll()
{
    for (size_t i = 0; i < m_terrain[0].size(); i++)
        for (size_t j = 0; j < m_terrain.size(); j++)
            move({ i, j });
}


void GameEngine::drawTerrain() const
{
    std::cout << "  ";

    for (size_t i = 0; i < m_terrain[0].size(); i++)
        std::cout << i << " ";
    
    std::cout << "\n";

    for (size_t i = 0; i < m_terrain.size(); i++) {
        std::cout << i << " ";
        for (size_t j = 0; j < m_terrain[i].size(); j++) {
            m_terrain[i][j]->draw();
            std::cout << " ";
        }
        std::cout << "\n";
    }
}


void GameEngine::shoot(Coord pos, int dmg)
{
    IShootable* s = dynamic_cast<IShootable*>(m_terrain[pos.y][pos.x]);
    if (s) {
        s->getShot(dmg);
    }
}


void GameEngine::run()
{
    for (size_t i = 0; i < 12; i++) {
        moveAll();
        drawTerrain();
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
}
