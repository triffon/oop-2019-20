#ifndef HORSE_H
#define HORSE_H
#include "Animal.h"
/// Virtual inheritance allow us to fight the diamond problem and instantiate only one animal and avoid ambiguity
class Horse : virtual public Animal
{
    public:
        Horse();
        virtual Horse * clone();
        virtual void wakeUp();
        virtual ~Horse();

    protected:

    private:
};

#endif // HORSE_H
