#ifndef __NAMED_HPP
#define __NAMED_HPP

class Named {
    char* name;

public:
    Named(char const* n = "<анонимен>");
    Named(Named const&);
    Named& operator=(Named const&);
    ~Named();

    // TODO: напишете селектора така, че да не "издава" указателя
    char const* getName() const { return name; }

    void setName(char const* n);
};

#endif