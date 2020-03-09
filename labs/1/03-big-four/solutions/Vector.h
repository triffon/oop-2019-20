#pragma once

class Vector
{
public:
    // Big four
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

public:
    // Methods
    int size();
    int capacity();
    int& at(int index);
    void push_back(int element);
    void erase(int index);
    void reserve(int capacity);

private:
    // Helper methods used in the big four
    void copy(const Vector& other);
    void clear();

private:
    // Data members should always be private
    int m_size;
    int m_capacity;
    int* m_arr;
};
