#include <cstring>
#include <algorithm>
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


const char* Beer::getBrand()
{
    return brand;
}


int Beer::getVolume()
{
    return volume;
}


void Beer::setBrand(const char* brand)
{
    if (brand != nullptr)
        strcpy(this->brand, brand);
}


void Beer::setVolume(int volume)
{
    if (volume >= 0)
        this->volume = volume;
}


void Beer::addBeer(Beer& other, int amount)
{
    int actualAmount = std::min(amount, other.volume);

    if (actualAmount > 0) {
        strcat(this->brand, "&");
        strcat(this->brand, other.brand);
        this->volume += actualAmount;
        other.volume -= actualAmount;
    }
}


bool Beer::hasBrand(const char* otherBrand)
{
    const char* pCurr = this->brand;
    const char* pOther = otherBrand;
    while (*pCurr) {
        while (*pCurr == *pOther) {
            ++pCurr;
            ++pOther;
            if (*pOther == '\0' && (*pCurr == '\0' || *pCurr == '&'))
                return true;
        }

        while (*pCurr && *pCurr != '&')
            ++pCurr;

        if (*pCurr == '&') {
            ++pCurr;
            pOther = otherBrand;
        }
    }

    return false;
}
