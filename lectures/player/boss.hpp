#ifndef __BOSS_HPP
#define __BOSS_HPP

#include "hero.hpp"
#include "bot.hpp"

class Boss : public Hero, public Bot {
    unsigned damage;

public:
    Boss(char const* n = "<таен boss>", unsigned s = 0, unsigned lvl = 100,
         char const* algo = "<неизвестен алгоритъм>", double t = .3,
         unsigned diff = 10, unsigned dmg = 5);
    
    unsigned getDamage() const { return damage; }

    void printDirect(std::ostream& os = std::cout) const;
    void print(std::ostream& os = std::cout) const;
};

#endif