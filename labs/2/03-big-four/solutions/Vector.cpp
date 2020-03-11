#include "Vector.h"

const int DEFAULT_CAPACITY = 4;

Vector::Vector()
{
    m_size = 0;
    m_capacity = DEFAULT_CAPACITY;
    m_arr = new int[m_capacity];
}


Vector::Vector(const Vector& other)
{
    copy(other);
}


Vector& Vector::operator=(const Vector& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


Vector::~Vector()
{
    clear();
}


void Vector::copy(const Vector& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_arr = new int[m_capacity];
    for (int i = 0; i < m_size; i++)
        m_arr[i] = other.m_arr[i];
}


void Vector::clear()
{
    delete[] m_arr;
    m_arr = nullptr;
}


int Vector::size()
{
    return m_size;
}


int Vector::capacity()
{
    return m_capacity;
}


int& Vector::at(int index)
{
    return m_arr[index];
}


void Vector::push_back(int element)
{
    if (m_size >= m_capacity)
        reserve(2 * m_capacity);
    
    m_arr[m_size] = element;
    ++m_size;
}


void Vector::erase(int index)
{
    for (int i = index; i < m_size - 1; i++)
        m_arr[i] = m_arr[i + 1];
    m_size--;
}


void Vector::reserve(int capacity)
{
    if (capacity > m_capacity) {
        m_capacity = capacity;
        int* new_arr = new int[capacity];
        for (int i = 0; i < m_size; i++)
            new_arr[i] = m_arr[i];

        delete[] m_arr;
        m_arr = new_arr;
    }
}
