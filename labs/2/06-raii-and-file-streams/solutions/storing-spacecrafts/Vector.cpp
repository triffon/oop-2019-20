#include <algorithm>
#include "Vector.h"

const int DEFAULT_CAPACITY = 4;

Vector::Vector(int capacity)
    : m_size(0)
    , m_capacity(std::max(capacity, DEFAULT_CAPACITY))
    , m_arr(new elem_t[m_capacity])
{}


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
    m_arr = new elem_t[m_capacity];
    for (int i = 0; i < m_size; i++)
        m_arr[i] = other.m_arr[i];
}


void Vector::clear()
{
    delete[] m_arr;
    m_arr = nullptr;
}


void Vector::push_back(const elem_t& element)
{
    if (m_size >= m_capacity)
        reserve(2 * m_capacity);
    
    m_arr[m_size] = element;
    ++m_size;
}


void Vector::erase(int index)
{
    --m_size;
    for (int i = index; i < m_size; i++)
        m_arr[i] = m_arr[i + 1];
}


void Vector::reserve(int capacity)
{
    if (capacity > m_capacity) {
        m_capacity = capacity;
        elem_t* new_arr = new elem_t[capacity];

        for (int i = 0; i < m_size; i++)
            new_arr[i] = m_arr[i];

        delete[] m_arr;
        m_arr = new_arr;
    }
}


void Vector::serialize(std::ofstream& out) const
{
    out.write((const char*) &m_size, sizeof(m_size));
    out.write((const char*) &m_capacity, sizeof(m_capacity));
    for (int i = 0; i < m_size; i++)
        m_arr[i].serialize(out);
}


void Vector::deserialize(std::ifstream& in)
{
    clear();
    in.read((char*) &m_size, sizeof(m_size));
    in.read((char*) &m_capacity, sizeof(m_capacity));
    m_arr = new elem_t[m_capacity];
    for (int i = 0; i < m_size; i++)
        m_arr[i] = elem_t(in);
}


elem_t& Vector::operator[](int index)
{
    return at(index);
}


const elem_t& Vector::operator[](int index) const
{
    return at(index);
}


Vector& Vector::operator+=(const elem_t& elem)
{
    push_back(elem);
    return *this;
}


Vector& Vector::operator+=(const Vector& other)
{
    reserve(m_size + other.m_size);
    for (int i = 0; i < other.m_size; i++)
        *this += other[i];
    return *this;
}


std::ostream& operator<<(std::ostream& out, const Vector& obj)
{
    out << "[ ";

    if (obj.size() >= 1)
        out << obj[0];

    for (int i = 1; i < obj.size(); i++)
        out << ", " << obj[i];

    out << " ]";
    return out;
}
