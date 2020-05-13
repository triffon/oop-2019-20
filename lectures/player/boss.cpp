#include "boss.hpp"

Boss::Boss(char const* n, unsigned s, unsigned lvl,
         char const* algo, double t,
         unsigned diff, unsigned dmg) :
         Player(n, s), Hero("<глупост1>", s, lvl), Bot("<глупост2>", s, algo, t, diff), damage(dmg) {}

void Boss::printDirect(std::ostream& os) const {
    Hero::printDirect(os);
    std::cout << " и е бос, който нанася щети " << getDamage() << ',';
    Bot::printDirect(os);
}

void Boss::print(std::ostream& os) const {
    Player::print(os);
    printDirect(os);
}