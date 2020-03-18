#include <cstring>
#include "player.hpp"

Player::Player(char const* n, unsigned s) : score(s) {
    strcpy(name, n);
}