//
// Created by yasen on 3/8/20.
//

#ifndef MARTA_SPROJECT_MARTENITSA_H
#define MARTA_SPROJECT_MARTENITSA_H


#include <cstdio>

class Martenitsa {

public:
    Martenitsa();
    Martenitsa(const char*, const char*, size_t, size_t);
    Martenitsa(const Martenitsa&);
    Martenitsa&operator=(const Martenitsa&);
    ~Martenitsa();

public:
    void print() const;
    void readFromConsole();
    bool lessThen(const Martenitsa&) const;
    bool graterThen(const Martenitsa&) const;
private:
    void copyFrom(const Martenitsa&);
    void clean();
    void init(const char*, const char*, size_t, size_t);

private:
    char* fStudentName;
    char* fWish;
    size_t fLength;
    size_t fCountBeads;
};


#endif //MARTA_SPROJECT_MARTENITSA_H
