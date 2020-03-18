#include <cstring>
#include <iostream>
#include "player.hpp"

Player::Player(char const* n, unsigned s) : name(nullptr), score(s) {
    // !  strcpy(name, n);
    setName(n);
}

void Player::setName(char const* n) {
    // разчитаме, че за name има заделена памет и в нея има записано нещо
    // изтриваме старата памет
    delete[] name;
    // заделяме нова
    name = new char[strlen(n) + 1];
    // сигурни сме, че имаме достатъчно памет
    strcpy(name, n);
}

void Player::print() const {
    std::cout << "Играчът " << getName() << " има " << getScore() << " точки" << std::endl;
}

Player::Player(Player const& p) : name(nullptr), score(p.score) {
    setName(p.name);
}

Player::~Player() {
    delete[] name;
}