#ifndef __ANIMAL_TYPE_H__
#define __ANIMAL_TYPE_H__

enum TypeStatus {
    safe, endangered, extinct
};

class AnimalType {

public:
    AnimalType();
    AnimalType(const char *, double, TypeStatus);
    AnimalType(const char *, double, const char *);
    AnimalType(AnimalType const &);
    AnimalType & operator=(AnimalType const &);
    ~AnimalType();
    friend std::ostream& operator<<(std::ostream&, AnimalType&);
    void print();
    const char * printStatus();
    const char * getName();
    double getLifetime();

private:
    char * name;
    double lifetime;
    TypeStatus status;
    void setNameFromString(const char *);

};


#endif