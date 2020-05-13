#include "hero.hpp"

Hero::Hero(char const* n, unsigned s, unsigned lvl) : level(lvl), Player(n, s) {
    // !!! Player(n, s);
    // !!! setName(n);
    // !!! setScore(s);
}

void Hero::printDirect(std::ostream& os) const {
    os << " и е герой на ниво " << getLevel();
}

void Hero::print(std::ostream& os) const {
    Player::print(os);
    printDirect(os);
}