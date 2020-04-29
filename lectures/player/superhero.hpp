#include "hero.hpp"

class SuperHero : public Hero {
    char* power;
    bool usingPower;
    unsigned levelBoost;

    void setPower(char const* p);
public:
    SuperHero(char const* n = "<неизвестен>",
              unsigned s = 0,
              unsigned lvl = 1,
              char const* p = "<мистериозна>",
              unsigned lvlBoost = 1);
    SuperHero(SuperHero const&);
    SuperHero& operator=(SuperHero const&);
    ~SuperHero();

    char const* getPower() const { return power; }

    // предефиниран селектор, който взима предвид дали се използва суперсилата
    unsigned getLevel() const;

    void usePower()       { usingPower = true;  }
    void stopUsingPower() { usingPower = false; }

// ! private:
    void print(std::ostream& os = std::cout) const;
};
