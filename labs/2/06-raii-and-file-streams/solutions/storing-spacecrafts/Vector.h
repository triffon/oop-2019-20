#pragma once
#include <iostream>
#include <fstream>
#include "Spacecraft.h"

typedef Spacecraft elem_t;

class Vector
{
public:
    // Big four
    Vector(int capacity = 0);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    // Methods
    inline int size() const { return m_size; }
    inline int capacity() const { return m_capacity; }
    inline elem_t& at(int index) { return m_arr[index]; }
    inline const elem_t& at(int index) const { return m_arr[index]; }
    void push_back(const elem_t& element);
    void erase(int index);
    void reserve(int capacity);
    void deserialize(std::ifstream& in);
    void serialize(std::ofstream& out) const;

    // Operators
    elem_t& operator[](int index);
    const elem_t& operator[](int index) const;
    Vector& operator+=(const elem_t& elem);
    Vector& operator+=(const Vector& other);

private:
    // Helper methods used in the big four
    void copy(const Vector& other);
    void clear();

    // Data members
    int m_size;
    int m_capacity;
    elem_t* m_arr;
};

std::ostream& operator<<(std::ostream& out, const Vector& obj);
