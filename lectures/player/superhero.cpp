#include <cstring>
#include "superhero.hpp"

SuperHero::SuperHero(char const* n,
                     unsigned s,
                     unsigned lvl,
                     char const* p,
                     unsigned lvlBoost)
    : Hero(n, s, lvl), levelBoost(lvlBoost), usingPower(false),
      // важно е да инициализираме power с nullptr, заради delete в setPower
      power(nullptr) {
    setPower(p);
}

unsigned SuperHero::getLevel() const {
    if (!usingPower)
        return Hero::getLevel();
    return Hero::getLevel() + levelBoost;
}

void SuperHero::print(std::ostream& os) const {
    if (!usingPower) {
        Hero::print(os);
        os << " със скрита суперсила";
    } else {
        Player::print(os);
        os << " и е супергерой на ниво " << getLevel() << ", който използва суперсила " << getPower();
    }
    
}

void SuperHero::setPower(char const* p) {
    // разчитаме, че за name има заделена памет и в нея има записано нещо
    // изтриваме старата памет
    delete[] power;
    // заделяме нова
    power = new char[strlen(p) + 1];
    // сигурни сме, че имаме достатъчно памет
    strcpy(power, p);
}

SuperHero::~SuperHero() {
    std::clog << "~SuperHero()" << std::endl;
    delete[] power;
}

SuperHero::SuperHero(SuperHero const& sh) 
    : Hero(sh), power(nullptr), levelBoost(sh.levelBoost), usingPower(sh.usingPower) {
    setPower(sh.power);
}

SuperHero& SuperHero::operator=(SuperHero const& sh) {
    if (&sh != this) {
        Hero::operator=(sh);
        // !!! *this = (Hero const&)sh;
        // (Hero&)*this = sh;
        // *(Hero*)this = sh;
        levelBoost = sh.levelBoost;
        usingPower = sh.usingPower;
        setPower(sh.power);
    }
    return *this;
}