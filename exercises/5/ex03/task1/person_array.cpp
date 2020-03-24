#include "person_array.hpp"
#include "person.hpp"

PersonArray::PersonArray() {
    count = 0;
    reservedCount = 32;
    data = new Person[reservedCount];
}

PersonArray::~PersonArray() {
    delete[] data;
}

void PersonArray::push(Person & p) {
    if (count == reservedCount) {
        Person * newData = new Person[reservedCount * 2];
        for (int i = 0; i < count; ++i) {
            newData[i] = data[i];
        }

        reservedCount *= 2;
        delete[] data;
        data = newData;
    }
    data[count++] = p;
}

Person & PersonArray::get(int i) {
    return data[i];
}

int PersonArray::size() {
    return count;
}