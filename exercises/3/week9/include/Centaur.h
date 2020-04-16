#ifndef CENTAUR_H
#define CENTAUR_H
#include "Horse.h"
#include "Human.h"
/// Centaur has exactly one instance of Animal because of the virtual inheritances
class Centaur : public Human, Horse
{
    public:
        Centaur();
        virtual void wakeUp();
        virtual ~Centaur();

    protected:

    private:
};

#endif // CENTAUR_H
