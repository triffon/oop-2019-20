#include <iostream>
#include "player.hpp"

void anonymousPrint(Player p) {
    p.setName("Анонимен");
    p.print();
}

void testPlayer() {
    Player p1("Гандалф Сивия", 45);
    Player p2 = p1;
    p1.print();
    p2.setName("Гандалф Белия");
    p1.print();
    p2.print();
    anonymousPrint(p2);
    p2.print();
    Player("Соник таралежът", 100).print();
    // !!! delete p1.getName();
    // !!! p1.~Player();
}

int main() {
    testPlayer();
    return 0;
}