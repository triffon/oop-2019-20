//
// Created by tony on 19.03.20 г..
//

#ifndef FMIOOP_VECTOR_H
#define FMIOOP_VECTOR_H


class Vector {
    int *data;
    int size;
    int capacity;

    void clean();
    void copy(const Vector& other);
    void resize();
    void shiftLeft(int);
public:
    Vector();
    Vector(int capacity);
    ~Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);

    void add(int num);
    int getAt(int index);
    bool removeAt(int index);
    int getSize();
    int getMin();

    Vector& operator+(Vector &other);
    operator int();
    int operator[](int index);
};


#endif //FMIOOP_VECTOR_H
