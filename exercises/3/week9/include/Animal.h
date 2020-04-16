#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
    public:
        Animal(int age=0);
        /// These trivial getters and setters are inherited in all of the child classes
        void setAge(int age);
        int getAge()const;
        /// virtual functions allow us to do polymorphism ( many shapes)
        /// Calling this on a Animal* will cause it invoke the function of the instantiated type (Human, Dog, etc.)
        virtual void wakeUp();
        /// Sometimes when we can't provide an implementation we can force the children of the class to provide such
        /// This is called pure virtual function
        /// virtual void wakeUp()=0;
        /// Important!!! When a class has at least one pure virtual function it is called abstract class and is not allow to make instances from it

        /// The destructor is virtual so when we call delete on Animal * it will call the destructor for the instantiated type
        /// This will allow us to handle dynamically allocated data in the children
        virtual ~Animal();

    protected:
        /// Protected data is data that is not visible to the outside world but it is visible in the child classes
        int age;
    private:
};

#endif // ANIMAL_H
