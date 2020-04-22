#include "hero.hpp"

Hero::Hero(char const* n, unsigned s, unsigned lvl) : level(lvl) {
    // !!!    Player(n, s);
    setName(n);
    setScore(s);
}

void Hero::print(std::ostream& os) const {
    Player::print(os);
    os << " и е герой на ниво " << getLevel();
}

std::ostream& operator<<(std::ostream& os, Hero const& h) {
    h.print(os);
    return os << std::endl;
}
