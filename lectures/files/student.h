#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>

const unsigned MAX_NAME = 100;

// TODO: да се направи на клас
struct Student {
    char name[MAX_NAME];
    unsigned fn;
    double grade;

    // неформатиран изход
    void write(std::ostream& os) {
        os.write((char const*)this, sizeof(Student));
    }

    // неформатиран вход
    void read(std::istream& is) {
        is.read((char*)this, sizeof(Student));
    }
};

// форматиран изход
std::ostream& operator<<(std::ostream& os, Student const& s) {
    return os << s.fn << ' ' << s.grade << ' ' << s.name << std::endl;
}

// форматиран вход
std::istream& operator>>(std::istream& is, Student& s) {
    return (is >> s.fn >> s.grade).getline(s.name, MAX_NAME);
}

#endif