//
// Created by tony on 19.03.20 г..
//

#include "Vector.h"
Vector::Vector()
{
    capacity = 16;
    data = new int[capacity];
    size = 0;
}

Vector::Vector(int capacity)
{
    this->capacity = capacity;
    data = new int[capacity];
    size = 0;
}

Vector::~Vector()
{
    clean();
}

void Vector::clean()
{
    delete[] data;
    data = nullptr;
}

Vector::Vector(const Vector &other)
{
    copy(other);
}

Vector& Vector::operator=(const Vector &other)
{
    if(this != &other)
    {
        clean();
        copy(other);
    }
    return *this;
}

void Vector::copy(const Vector& other)
{
    data = new int[other.capacity];
    size = other.size;
    capacity = other.capacity;
    for(int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

void Vector::add(int num)
{
    if(size == capacity)
    {
        resize();
    }
    data[size++] = num;
}

void Vector::resize()
{
    capacity *= 2;
    int *result = new int [capacity];
    for(int i = 0; i < size; i++)
    {
        result[i] = data[i];
    }
    clean();
    data = result;
}

int Vector::getAt(int index)
{
    return data[index];
}

bool Vector::removeAt(int index)
{
    if(size == 0 or index > size)
    {
        return 0;
    }
    shiftLeft();
    size--;
    return 1;

}

void Vector::shiftLeft(int index)
{
    for(int i = index; i < size - 1; i++)
    {
        data[i] = data[i+1];
    }
}

int Vector::getSize()
{
    return size;
}

int Vector::getMin()
{
    int min = data[0];
    for(int i = 1; i < size; i++)
    {
        if(min > data[i])
        {
            min = data[i];
        }
    }
    return min;
}

Vector& Vector::operator+(Vector &other)
{
    Vector *result = new Vector();
    for(int i = 0; i < size; i++)
    {
        result->add(data[i]);
    }
    for(int i = 0; i <other.size; i++)
    {
        result->add(other.data[i]);
    }
    return *result;
}

Vector::operator int()
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum;
}

int Vector::operator[](int index)
{
    return data[index];
}
