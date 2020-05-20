#pragma once
#include "ArrayVector.hpp"

template <typename T>
class Set : ICollection<T>
{
public:
	bool member(const T&) const;
	bool add(const T&);
	bool remove(const T&);
	size_t getSize() const;
	T& operator [] (int i);
	const T& operator [] (int i) const;
	//int indexOf(const T&) const;
	void print() const;

public:
	Set(ArrayVector<T> _store = ArrayVector<T>());
private:
	ArrayVector<T> store;
};

template<typename T>
inline bool Set<T>::member(const T& element) const
{
	return store.member(element);
}

template<typename T>
inline bool Set<T>::add(const T& element)
{
	if (store.member(element))
	{
		return false;
	}

	store.add(element);
	return true;
}

template<typename T>
inline bool Set<T>::remove(const T& element)
{
	return store.remove(element);
}

template<typename T>
inline size_t Set<T>::getSize() const
{
	return store.getSize();
}

template<typename T>
inline T& Set<T>::operator[](int i)
{
	return store[i];
}

template<typename T>
inline const T& Set<T>::operator[](int i) const
{
	return store[i];
}

template<typename T>
inline void Set<T>::print() const
{
	store.print();
}

template<typename T>
inline Set<T>::Set(ArrayVector<T> _store) : store(_store) {}
