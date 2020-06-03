#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std::endl;

class Person {

public:
    Person();
    Person(int, const char *, double);
    Person(Person const &);
    Person & operator=(Person const &);
    ~Person();

    void print() const;
    long int readFromFile(const char *, long int);
    void saveToFile(const char *, bool) const;

    char * getName();

private:
    int id;
    char * name;
    double age;

};

Person::Person() : id(0), age(0) {
    name = new char[1];
    name[0] = 0;
}

Person::Person(int _id, const char * _name, double _age) : id(_id), age(_age) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

Person::Person(Person const & p) : id(p.id), age(p.age) {
    if (&p != this) {
        delete[] name;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }
}

Person & Person::operator=(Person const & p) {
    if (&p != this) {
        id = p.id;
        age = p.age;

        delete[] name;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }

    return *this;
}

Person::~Person() {
    delete[] name;
}

void Person::print() const {
    cout << id << " " << name << " " << age << endl;
}

char * Person::getName() {
    return name;
}

long int Person::readFromFile(const char * filename, long int offset = 0) {
    long int bytes = 0;

    std::fstream file(filename, std::ios::in | std::ios::binary);
    file.seekp(offset);

    file.read((char *)&id, sizeof(id));
    bytes += sizeof(id);

    file.read((char *)&age, sizeof(age));
    bytes += sizeof(age);

    delete[] name;
    int nameLength;
    file.read((char *)&nameLength, sizeof(nameLength));
    bytes += sizeof(nameLength);

    name = new char[nameLength + 1];
    file.read(name, nameLength);
    name[nameLength] = 0;
    bytes += nameLength;

    file.close();

    return bytes;
}

void Person::saveToFile(const char * filename, bool truncate = true) const {
    std::fstream file(filename, std::ios::out | std::ios::binary | (truncate ? std::ios::trunc : std::ios::app));

    file.write((char *)&id, sizeof(id));
    file.write((char *)&age, sizeof(age));
    int nameLength = strlen(name);
    file.write((char *)&nameLength, sizeof(nameLength));
    file.write(name, nameLength);

    file.close();
}

int main() {
    Person p1(1, "Ivan Ivanov", 22);
    Person p2(2, "Pesho", 21);

    p1.print();
    p2.print();

    cout << sizeof(Person) << " " << sizeof(p2) << endl;
    cout << sizeof(*(p1.getName())) << " " << sizeof(*(p2.getName())) << endl;

    p1.saveToFile("p1.bin");

    Person p3;
    p3.readFromFile("p1.bin");
    p3.print();

    Person p4(3, "Tosho", 24);

    int count = 7;
    Person ps[10];
    ps[0] = p1;
    ps[1] = p2;
    ps[2] = p4;
    ps[3] = p1;
    ps[4] = p2;
    ps[5] = p4;
    ps[6] = p1;

    std::fstream file1("db.bin", std::ios::out | std::ios::binary);
    file1.write((char *) &count, sizeof(count));
    file1.close();
    for (int i = 0; i < count; ++i) {
        ps[i].print();
        ps[i].saveToFile("db.bin", false);
    }

    int count2 = 7;
    Person ps2[10];

    std::fstream file2("db.bin", std::ios::in | std::ios::binary);
    file2.read((char *) &count2, sizeof(count2));
    file2.close();
    long int offset = sizeof(count2);
    for (int i = 0; i < count2; ++i) {
        offset += ps2[i].readFromFile("db.bin", offset);

        ps2[i].print();
    }

    return 0;
}
