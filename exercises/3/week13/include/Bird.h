#ifndef BIRD_H
#define BIRD_H
#include "Animal.h"

class Bird : public Animal
{
    public:
        Bird(int age);
        void sleep();
        void fly();
        virtual ~Bird();

    protected:

    private:
};

#endif // BIRD_H
