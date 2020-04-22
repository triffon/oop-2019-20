#include "Duck.h"

Duck::Duck( const char * src ): Animal( src )
{

}

void Duck::makeSound()
{

	std::cout << "Duck with name " << name << " : quack ! \n";
}

Animal* Duck::clone()
{
	return new Duck( *this );
}