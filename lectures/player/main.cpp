#include <iostream>
#include "player.hpp"
#include "hero.hpp"
#include "superhero.hpp"

void anonymousPrint(Player p) {
    p.setName("Анонимен");
    p.print();
}

void testPlayer() {
    Player p1("Гандалф Сивия", 45);
    Player p2;
    p2 = p1;
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

void testHero() {
    Hero h1;
    Hero h2("Гандалф Сивия", 45, 10);
    std::cout << h1;
    std::cout << h2;
    Player p = h2;
    std::cout << p;
    Hero& h3 = h2;
    Player* pp = &h3;
    std::cout << (*pp);
    Player& rp = h1;
    std::cout << rp;
    rp = h2; // Player::operator=
    std::cout << rp;
    std::cout << h1;
    h1 = h2; // Hero::operator=
    std::cout << h1;

    Player p2("Катнис Евърдийн", 55);
    Hero h4 = (Hero const&)p2;
    std::cout << h4;
    // !!! pp = &p2;
    Hero* ph = (Hero*)pp;
    std::cout << *ph << std::endl;
}

void testSuperHero() {
    SuperHero sh("Супермен", 60, 5, "летене", 10);
    std::cout << sh;
    sh.usePower();
    std::cout << sh;
    sh.stopUsingPower();
    std::cout << sh;

    SuperHero shdefault;
    std::cout << shdefault;
    shdefault.usePower();
    std::cout << shdefault;
    shdefault.stopUsingPower();
    std::cout << shdefault;

    SuperHero sh2 = sh;
    std::cout << sh2;

    shdefault = sh;
    std::cout << shdefault;
}

int main() {
    // testPlayer();
    // testHero();
    testSuperHero();
    return 0;
}