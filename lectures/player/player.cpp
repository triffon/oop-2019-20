#include <cstring>
#include <iostream>
#include "player.hpp"

Player::Player(char const* n, unsigned s) : score(s) {
    // !  strcpy(name, n);
    setName(n);
}

void Player::setName(char const* n) {
    strncpy(name, n, MAX_NAME);
    name[MAX_NAME-1] = '\0';
}

void Player::print() const {
    std::cout << "Играчът " << getName() << " има " << getScore() << " точки" << std::endl;
}