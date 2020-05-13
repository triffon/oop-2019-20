#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>

template <typename TYPE>
class Vector {
protected:
  TYPE* data;
  unsigned reservedSpace;
  unsigned count;
  static const unsigned MINIMUM_SPACE = 32;

public:
  Vector();
  Vector(Vector const &);
  ~Vector();

  Vector &operator=(Vector const &);
  TYPE &operator[](unsigned);

  template <typename T>
  friend std::ostream &operator<<(std::ostream &, Vector<T> &);

  unsigned size() const;
  void push(TYPE const &);
  void remove(unsigned);
};


template <typename TYPE>
Vector<TYPE>::Vector() {
  reservedSpace = MINIMUM_SPACE;
  data = new TYPE[reservedSpace];
  count = 0;
}

template <typename TYPE>
Vector<TYPE>::Vector(Vector const &temp) {
  reservedSpace = temp.reservedSpace;
  data = new TYPE[reservedSpace];
  count = temp.count;

  for(unsigned i=0; i<count; ++i) {
    data[i] = temp.data[i];
  }
}

template <typename TYPE>
Vector<TYPE>::~Vector() {
  delete[] data;
}

template <typename TYPE>
Vector<TYPE> &Vector<TYPE>::operator=(Vector const &temp) {
  delete[] data;

  reservedSpace = temp.reservedSpace;
  count = temp.count;
  data = new TYPE[reservedSpace];

  for(unsigned i=0; i<count; ++i) {
    this->data[i] = temp.data[i];
  }
  return *this;
}

template <typename TYPE>
TYPE& Vector<TYPE>::operator[](unsigned i) {
  return data[i];
}

template <typename TYPE>
std::ostream &operator<<(std::ostream &ostr, Vector<TYPE> &temp) {
  for(unsigned i=0, sze=temp.size(); i<sze; ++i) {
    ostr << temp[i];
  }
  return ostr;
}

template <typename TYPE>
unsigned Vector<TYPE>::size() const {
  return count;
}

template <typename TYPE>
void Vector<TYPE>::push(TYPE const &t) {
  if (count == reservedSpace) {
    reservedSpace *= 2;
    TYPE* newData = new TYPE[reservedSpace];
    for (unsigned i=0; i<count; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }
  data[count++] = t;
}

template <typename TYPE>
void Vector<TYPE>::remove(unsigned ind) {
  if(ind >= count) {
    return;
  }
  else {
    TYPE* newData = new TYPE[reservedSpace];
    for(unsigned i=0; i<ind; ++i) {
      newData[i] = data[i];
    }
    count--;
    for(unsigned i=ind; i<count; ++i) {
      newData[i] = data[i+1];
    }
    delete[] data;
    data = newData;
  }
}

#endif
