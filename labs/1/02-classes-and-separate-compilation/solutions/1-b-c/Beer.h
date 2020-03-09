#pragma once

const int MAX_BRAND_LEN = 128;

class Beer
{
public:
    // Constructors
    Beer();
    Beer(const char* brand, int volume);

    // Getters and setters
    const char* getBrand();
    int getVolume();
    void setBrand(const char* brand);
    void setVolume(int volume);

    // Methods
    void addBeer(Beer& other, int amount);
    bool hasBrand(const char* otherBrand);

private:
    char brand[MAX_BRAND_LEN];
    int volume;
};
