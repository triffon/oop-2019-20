#ifndef HUMAN_H
#define HUMAN_H
#include "Animal.h"
/// There are three inheritance types ( public, protected and private) which decide the access modifiers from the inherited data
/// In most cases public is what you want because it preserves all the access modifiers from the parent
/// Here is a small table showing how the access modifiers change according to the inheritance type
/// public inheritance: public -> public , protected -> protected
/// protected inheritance: public -> protected , protected -> protected
/// private inheritance: public -> private, protected -> private
/// private data is still inherited but it is not accessible(if you have for example a public getter/setter you can still use it)

/// Virtual inheritance allow us to fight the diamond problem and instantiate only one animal and avoid ambiguity
class Human : virtual public Animal
{
    public:
        Human(char * name=nullptr,int age=0);

        virtual void wakeUp();
        /// trivial getters and setters
        void setName(const char * name);
        char * getName()const;
        /// for why the destructor is virtual read Animal.h
        virtual ~Human();

    protected:

    private:
        char * name=nullptr;
};

#endif // HUMAN_H
