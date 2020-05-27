#include <cassert>
#include <cstring>
#include "named.hpp"

void Named::setName(char const* n) {
    assert(n != nullptr);
    // разчитаме, че за name има заделена памет и в нея има записано нещо
    // изтриваме старата памет
    delete[] name;
    // заделяме нова
    name = new char[strlen(n) + 1];
    // сигурни сме, че имаме достатъчно памет
    strcpy(name, n);
}

Named::Named(char const* n) : name(nullptr) {
    setName(n);
}

Named::Named(Named const& p) : name(nullptr) {
    setName(p.name);
}

Named& Named::operator=(Named const& p) {
    if (this != &p)
        setName(p.name);
    return *this;
}

Named::~Named() {
    delete[] name;
}