#include "Dog.h"

Dog::Dog( const char* src ) : Animal(src)
{
}

void Dog::makeSound()
{

	std::cout << "Dog with name " << name << " : bark! \n";
}

Animal* Dog::clone()
{
	return new Dog( *this );
}