#ifndef ANIMAL_H
#define ANIMAL_H


class Animal
{
    public:

        Animal(int age);
        virtual void sleep();
        virtual ~Animal();

    protected:
        int age;
    private:

};

#endif // ANIMAL_H
