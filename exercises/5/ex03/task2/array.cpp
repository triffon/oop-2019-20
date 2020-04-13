#include "array.hpp"
#include "company.hpp"

Array::Array() {
  count = 0;
  reservedCount = 32;
  data = new Company[reservedCount];
}

Array::~Array() {
  delete[] data;
}

void Array::push(Company & p) {
  if (count >= reservedCount) {
    Company * newData = new Company[reservedCount * 2];
    for(int i = 0; i < count; i++) {
      newData[i] = data[i];
    }
    reservedCount *= 2;
    delete[] data;
    data = newData;
  }
  data[count++] = p;
}

Company & Array::get(int i) {
  return data[i];
}

int Array::size() {
  return count;
}
