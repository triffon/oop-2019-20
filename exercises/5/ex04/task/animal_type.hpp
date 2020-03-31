#ifndef __ANIMAL_TYPE_H__
#define __ANIMAL_TYPE_H__

enum TypeStatus {
    safe, endangered, extinct
};

class AnimalType {

public:
    AnimalType();
    AnimalType(const char *, double, TypeStatus);
    AnimalType(AnimalType const &);
    AnimalType & operator=(AnimalType const &);
    ~AnimalType();
    void print();
    const char * printStatus();

private:
    char * name;
    double lifetime;
    TypeStatus status;
    void setNameFromString(const char *);

};


#endif