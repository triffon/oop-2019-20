#pragma once
#include <iostream>

template <typename Elem_t>
class Vector
{
public:
    // Big four
    Vector(size_t capacity = 0);
    Vector(const Vector<Elem_t>& other);
    Vector<Elem_t>& operator=(const Vector<Elem_t>& other);
    ~Vector();

    // Methods
    inline size_t size() const { return m_size; }
    inline size_t capacity() const { return m_capacity; }
    inline bool empty() const { return m_size == 0; }
    Elem_t& at(size_t index);
    const Elem_t& at(size_t index) const;
    void push_back(const Elem_t& element);
    void pop_back();
    void insert(size_t index, const Elem_t& element);
    void erase(size_t index);
    void reserve(size_t capacity);

    // Operators
    Elem_t& operator[](size_t index);
    const Elem_t& operator[](size_t index) const;
    Vector<Elem_t>& operator+=(const Elem_t& elem);
    Vector<Elem_t>& operator+=(const Vector<Elem_t>& other);

private:
    // Helper methods used in the big four
    void copy(const Vector<Elem_t>& other);
    void clear();

    // Default capacity of the array
    static const size_t DEFAULT_CAPACITY;

    // Default resize factor of the array
    static const size_t RESIZE_FACTOR;

    // Data members
    size_t m_size;
    size_t m_capacity;
    Elem_t* m_arr;
};

#include "Vector.ipp"
