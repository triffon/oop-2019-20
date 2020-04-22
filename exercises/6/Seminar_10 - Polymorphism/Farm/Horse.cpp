#include "Horse.h"

Horse::Horse( const char * src ): Animal( src )
{

}

void Horse::makeSound()
{

	std::cout << "Horse with name " << name << " : whinny!\n";
}

Animal* Horse::clone()
{
	return new Horse( *this );
}