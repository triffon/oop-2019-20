#include <cstring>
#include "Beer.h"

Beer::Beer()
{
    brand[0] = '\0';
    volume = 0;
}


Beer::Beer(const char* brand, int volume) : Beer()
{
    setBrand(brand);
    setVolume(volume);
}


int Beer::getVolume()
{
    return volume;
}


void Beer::setVolume(int volume)
{
    if (volume >= 0)
        this->volume = volume;
}


const char* Beer::getBrand()
{
    return brand;
}


void Beer::setBrand(const char* brand)
{
    if (brand != nullptr)
        strcpy(this->brand, brand);
}
