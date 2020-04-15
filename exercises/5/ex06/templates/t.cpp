#include "t.hpp"

template <typename T>
Class<T>::Class() {
    std::cout << "Class()" << std::endl;
}

template <typename T>
Class<T>::~Class() {
    std::cout << "~Class()" << std::endl;
}