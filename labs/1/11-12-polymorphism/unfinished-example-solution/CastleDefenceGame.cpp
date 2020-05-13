#include <iostream>
#include "GameEngine.hpp"
#include "Soldier.hpp"
#include "Tank.hpp"
#include "Bush.hpp"
#include "Barrel.hpp"

int main()
{
    srand(time(nullptr));
    GameEngine g;

    g.addEntity(new Soldier, 2, 3);
    g.addEntity(new Bush, 5, 2);
    g.addEntity(new Barrel, 0, 0);
    g.addEntity(new Barrel, 7, 0);
    g.addEntity(new Soldier, 3, 1);
    g.addEntity(new Prop, 1, 2);
    g.addEntity(new Soldier, 8, 4);
    g.addEntity(new Tank, 9, 4);

    g.run();

    return 0;
}
