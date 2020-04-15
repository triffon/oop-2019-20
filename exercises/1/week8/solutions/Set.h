#pragma once

const int SET_INITIAL_CAPACITY = 4;

template <typename T>
class Set {

private:
	T* data;
	int size;
	int capacity;

	void copy(const Set<T>& s);

	void erase();

	void resize();

public:
	Set<T>();

	Set<T>(const Set<T>& s);

	Set<T>& operator=(const Set<T>& other);

	~Set<T>();

	int getSize() const;

	bool add(T element);

	bool contains(T element) const;

	bool isEmpty();

	bool remove(T element);

	T operator[](const int index) const;

	bool operator==(const Set<T>& other) const;

	Set<T> operator+(const Set<T>& other) const;

	Set<T> operator*(const Set<T>& other) const;

	Set<T> operator-(const Set<T>& other) const;

	template <typename S>
	friend ostream& operator<<(ostream& os, const Set<S>& set);
};


#include "Set.cpp"
