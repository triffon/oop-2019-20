#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "printable.hpp"
#include "named.hpp"
#include <iostream>

class Player : virtual public Printable, public Named {
    unsigned score;

protected:
    void setScore(unsigned s) { score = s; }

public:

    Player(char const* n = "<неизвестен>", unsigned s = 0);

/*
    char* opponentName = opponent.getName();
    strcpy(opponentName, "PWNED!!@1!");
*/

    unsigned getScore() const { return score; }
    void addPoints(unsigned pts) { score += pts; }

    virtual void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, Player const& p);

#endif