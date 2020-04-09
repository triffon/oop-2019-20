#include <iostream>
#include <fstream>

#include "animal.hpp"
#include "zoo.hpp"

Zoo::Zoo() {
    count = 0;
    reserved = INITIAL_RESERVED;
    data = new Animal[reserved];
    price = 0;
}

Zoo::~Zoo() {
    delete[] data;
}

Animal & Zoo::get(int i) {
    return data[i];
}

void Zoo::push(Animal & animal) {
    if (count == reserved) {

        Animal * newData = new Animal[reserved * 2];
        for (int i = 0; i < count; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;

        reserved *= 2;
    }
    data[count++] = animal;
}

int Zoo::size() const {
    return count;
}

double Zoo::getPrice() const {
    return price;
}

void Zoo::setPrice(double _price) {
    price = _price;
}

std::ostream& operator<<(std::ostream& ostr, Zoo& z) {
    ostr << "Entry price: " << z.price << std::endl;
    for (int i = 0; i < z.count; ++i) {
        ostr << i << ": " << z.data[i] << std::endl;
    }
    return ostr;
}

void Zoo::load(const char * filename) {
    delete[] data;
    count = 0;
    reserved = INITIAL_RESERVED;
    data = new Animal[reserved];

    std::fstream fin(filename, std::ios::in);

    fin >> price;
    
    int n;
    Animal a;
    char typeName[256];
    double typeLifetime;
    char typeStatus[64];

    char animalName[256];
    int animalAge;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin.getline(typeName, 256);
        fin.getline(typeName, 256);
        fin >> typeLifetime;
        fin >> typeStatus;

        AnimalType at(typeName, typeLifetime, typeStatus);
       
        fin.getline(animalName, 256);
        fin.getline(animalName, 256);
        fin >> animalAge;

        a.setName(animalName);
        a.setAge(animalAge);
        a.setType(at);

        push(a);
    }

    fin.close();
}

void Zoo::save(const char * filename) {
    std::fstream fout(filename, std::ios::out);

    fout << price << std::endl;

    fout << count << std::endl;
    for (int i = 0; i < count; ++i) {
        fout << data[i].getType().getName() << std::endl;
        fout << data[i].getType().getLifetime() << std::endl;
        fout << data[i].getType().printStatus() << std::endl;

        fout << data[i].getName() << std::endl;
        fout << data[i].getAge() << std::endl;
    }

    fout.close();
}