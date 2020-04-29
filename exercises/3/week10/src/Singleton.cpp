#include "Singleton.h"

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}
int Singleton::getData()const{
    return data;
};
void Singleton::setData(int data){
    this->data = data;
};
