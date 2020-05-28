#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

template <typename T>
class Vector {

public:
    Vector();
    Vector(Vector const &);
    Vector & operator=(Vector const &);
    ~Vector();
    Vector(int);
    int size() const;
    void push(T const &);
    T & operator[](int);
    T & get(int);
    void resize(int);

private:
    T * data;
    int reservedSpace;
    int count;
    static const int MINIMUM_SPACE = 32;

};

template <typename T>
Vector<T>::Vector() {
    reservedSpace = MINIMUM_SPACE;
    data = new T[reservedSpace];
    count = 0;
}

template <typename T>
Vector<T>::Vector(Vector const & v) {
    reservedSpace = v.reservedSpace;
    data = new T[reservedSpace];
    count = v.count;

    for (int i = 0; i < count; ++i) {
        data[i] = v.data[i];
    }
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector const & v) {
    delete[] data;

    reservedSpace = v.reservedSpace;
    count = v.count;
    data = new T[reservedSpace];

    for (int i = 0; i < count; ++i) {
        data[i] = v.data[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
Vector<T>::Vector(int size) {
    reservedSpace = size;
    data = new T[size];
    count = 0;
}

template <typename T>
int Vector<T>::size() const {
    return count;
}

template <typename T>
void Vector<T>::push(T const & t) {
    if (count == reservedSpace) {
        reservedSpace *= 2;
        T * newData = new T[reservedSpace];
        for (int i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[count++] = t;
}

template <typename T>
T & Vector<T>::operator[](int i) {
    if (count <= i) {
        resize(i + 1);
        count = i + 1;
    }
    return data[i];
}

template <typename T>
T & Vector<T>::get(int i) {
    if (count <= i) {
        resize(i + 1);
        count = i + 1;
    }
    return data[i];
}

template <typename T>
void Vector<T>::resize(int size) {
    T * newData = new T[size];
    if (size < count) {
        count = size;
    }
    for (int i = 0; i < count; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    reservedSpace = size;
}

#endif