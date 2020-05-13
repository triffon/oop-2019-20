#ifndef __HERO_HPP
#define __HERO_HPP

#include "player.hpp"

class Hero : virtual public Player {
    // ниво на Hero
    unsigned level;
public:
    Hero(char const* n = "<неизвестен>", unsigned s = 0, unsigned lvl = 1);

    virtual unsigned getLevel() const { return level; }

    void printDirect(std::ostream& os = std::cout) const;
    void print(std::ostream& os = std::cout) const;
};

#endif