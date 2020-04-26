#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <iostream>

class Player {
    char* name;
    unsigned score;

protected:
    void setScore(unsigned s) { score = s; }

public:

    Player(char const* n = "<неизвестен>", unsigned s = 0);
    Player(Player const&);
    Player& operator=(Player const&);
    ~Player();

    // TODO: напишете селектора така, че да не "издава" указателя
    char const* getName() const { return name; }
/*
    char* opponentName = opponent.getName();
    strcpy(opponentName, "PWNED!!@1!");
*/

    unsigned getScore() const { return score; }

    void setName(char const* n);

    void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, Player const& p);

#endif