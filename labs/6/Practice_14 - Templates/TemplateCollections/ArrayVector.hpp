#pragma once
#include "ICollection.h"

template <typename T>
class ArrayVector : public ICollection<T>
{
public:
	bool member(const T&) const;
	bool add(const T&);
	bool remove(const T&);
	size_t getSize() const;
	T& operator [] (int i);
	const T& operator [] (int i) const;
	int indexOf(const T&) const;
	void print() const;
public:
	ArrayVector(size_t _capacity = 10);
	ArrayVector(const ArrayVector<T>& other);
	ArrayVector<T>& operator=(const ArrayVector<T>& other);
	~ArrayVector();

private:
	void copy(const ArrayVector<T>& other);
private:
	T* elements;
	size_t size;
	size_t capacity;
};

template<typename T>
inline bool ArrayVector<T>::member(const T& element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] == element)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline bool ArrayVector<T>::add(const T& element)
{
	if (size >= capacity)
	{
		return false;
	}

	elements[size] = element;
	size++;
	return true;
}

template<typename T>
inline bool ArrayVector<T>::remove(const T& element)
{
	if (!member(element))
	{
		return false;
	}

	int index = indexOf(element);
	for (size_t i = index; i < size - 1; i++)
	{
		elements[i] = elements[i + 1];
	}
	size--;
	return true;
}

template<typename T>
inline size_t ArrayVector<T>::getSize() const
{
	return size;
}

template<typename T>
inline T& ArrayVector<T>::operator[](int i)
{
	if (i < 0 && i >= size)
	{
		throw std::out_of_range("Invalid index.");
	}

	return elements[i];
}

template<typename T>
inline const T& ArrayVector<T>::operator[](int i) const
{
	if (i < 0 && i >= size)
	{
		throw std::out_of_range("Invalid index.");
	}

	return elements[i];
}

template<typename T>
inline int ArrayVector<T>::indexOf(const T& element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] == element)
		{
			return i;
		}
	}

	return -1;
}

template<typename T>
inline void ArrayVector<T>::print() const
{
	std::cout << '[';
	for (size_t i = 0; i < size - 1; i++)
	{
		std::cout << elements[i] << ", ";
	}

	std::cout << elements[size - 1] << "] " << std::endl;
}

template<typename T>
inline ArrayVector<T>::ArrayVector(size_t _capacity)
	: size(0), capacity(_capacity), elements(new T[_capacity]) {}

template<typename T>
inline ArrayVector<T>::ArrayVector(const ArrayVector<T>& other)
{
	copy(other);
}

template<typename T>
inline ArrayVector<T>& ArrayVector<T>::operator=(const ArrayVector<T>& other)
{
	if (this != &other)
	{
		delete[] elements;
		copy(other);
	}

	return *this;
}

template<typename T>
inline ArrayVector<T>::~ArrayVector()
{
	delete[] elements;
}

template<typename T>
inline void ArrayVector<T>::copy(const ArrayVector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	elements = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		elements[i] = other.elements[i];
	}
}
