#ifndef __HERO_HPP
#define __HERO_HPP

#include "player.hpp"

class Hero : public Player {
    // ниво на Hero
    unsigned level;
public:
    Hero(char const* n = "<неизвестен>", unsigned s = 0, unsigned lvl = 1);

    unsigned getLevel() const { return level; }

    void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, Hero const& h);

#endif