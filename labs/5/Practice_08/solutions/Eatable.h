#pragma once

enum Taste { SWEET, SOUR, SALT, BITTER, SAVORY };

class Eatable {
    Taste taste;

public:
    Eatable(Taste = SWEET);
    void print();
};


