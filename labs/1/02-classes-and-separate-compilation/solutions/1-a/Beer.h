#pragma once

const int MAX_BRAND_LEN = 128;

class Beer
{
public:
    Beer();
    Beer(const char* brand, int volume);
    int getVolume();
    void setVolume(int volume);
    const char* getBrand();
    void setBrand(const char* brand);
    
private:
    char brand[MAX_BRAND_LEN];
    int volume;
};
