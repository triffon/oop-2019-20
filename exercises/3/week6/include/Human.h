#ifndef HUMAN_H
#define HUMAN_H
#include "Animal.h"

class Human : public Animal
{
    public:
        Human(int age);
        void sleep();
        void walk();
        virtual ~Human();
    protected:
    private:
};

#endif // HUMAN_H
