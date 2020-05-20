#include <iostream>
#include "player.hpp"

Player::Player(char const* n, unsigned s) : Named(n), score(s) {
}

void Player::print(std::ostream& os) const {
    os << "Играчът " << getName() << " има " << getScore() << " точки";
}

std::ostream& operator<<(std::ostream& os, Player const& p) {
    p.print(os);
    return os << std::endl;
}