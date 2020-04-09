#include <algorithm>
#include "Vector.hpp"

template <typename Elem_t>
const size_t Vector<Elem_t>::DEFAULT_CAPACITY = 8;

template <typename Elem_t>
const size_t Vector<Elem_t>::RESIZE_FACTOR = 2;


template <typename Elem_t>
Vector<Elem_t>::Vector(size_t capacity)
    : m_size(0)
    , m_capacity(0)
    , m_arr(nullptr)
{
    reserve(std::max(capacity, DEFAULT_CAPACITY));
}


template <typename Elem_t>
Vector<Elem_t>::Vector(const Vector<Elem_t>& other)
{
    copy(other);
}


template <typename Elem_t>
Vector<Elem_t>& Vector<Elem_t>::operator=(const Vector<Elem_t>& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}


template <typename Elem_t>
Vector<Elem_t>::~Vector()
{
    clear();
}


template <typename Elem_t>
void Vector<Elem_t>::copy(const Vector<Elem_t>& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_arr = new Elem_t[m_capacity];
    for (size_t i = 0; i < m_size; i++)
        m_arr[i] = other.m_arr[i];
}


template <typename Elem_t>
void Vector<Elem_t>::clear()
{
    delete[] m_arr;
    m_arr = nullptr;
}


template <typename Elem_t>
Elem_t& Vector<Elem_t>::at(size_t index)
{
    return m_arr[index];
}


template <typename Elem_t>
const Elem_t& Vector<Elem_t>::at(size_t index) const
{
    return m_arr[index];
}


template <typename Elem_t>
void Vector<Elem_t>::push_back(const Elem_t& element)
{
    if (m_size >= m_capacity)
        reserve(RESIZE_FACTOR * m_capacity);
    
    m_arr[m_size] = element;
    ++m_size;
}


template <typename Elem_t>
void Vector<Elem_t>::pop_back()
{
    --m_size;
}

template <typename Elem_t>
void Vector<Elem_t>::insert(size_t index, const Elem_t& element)
{
    if (m_size >= m_capacity)
        reserve(RESIZE_FACTOR * m_capacity);

    for (size_t i = m_size; i > index; i--)
        std::swap(m_arr[i], m_arr[i - 1]);

    m_arr[index] = element;
    ++m_size;
}


template <typename Elem_t>
void Vector<Elem_t>::erase(size_t index)
{
    for (size_t i = index; i < m_size - 1; i++)
        std::swap(m_arr[i], m_arr[i + 1]);
    --m_size;
}


template <typename Elem_t>
void Vector<Elem_t>::reserve(size_t capacity)
{
    if (capacity <= m_capacity)
        return;

    if (m_capacity == 0)
        m_capacity = DEFAULT_CAPACITY;

    while (capacity > m_capacity)
        m_capacity *= RESIZE_FACTOR;

    Elem_t* new_arr = new Elem_t[m_capacity];

    for (size_t i = 0; i < m_size; i++)
        new_arr[i] = m_arr[i];

    delete[] m_arr;
    m_arr = new_arr;
}


template <typename Elem_t>
Elem_t& Vector<Elem_t>::operator[](size_t index)
{
    return at(index);
}


template <typename Elem_t>
const Elem_t& Vector<Elem_t>::operator[](size_t index) const
{
    return at(index);
}


template <typename Elem_t>
Vector<Elem_t>& Vector<Elem_t>::operator+=(const Elem_t& elem)
{
    push_back(elem);
    return *this;
}


template <typename Elem_t>
Vector<Elem_t>& Vector<Elem_t>::operator+=(const Vector<Elem_t>& other)
{
    reserve(m_size + other.m_size);
    for (size_t i = 0; i < other.m_size; i++)
        *this += other[i];
    return *this;
}
