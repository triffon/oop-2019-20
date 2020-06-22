#pragma once
class ArraySet {
	int* data;
	size_t size;
	size_t capacity;

	void copy(const ArraySet& other);
	void clear();

	void expand();

	int indexOf(const int& element);

public:
	ArraySet();
	ArraySet(const ArraySet& other);
	ArraySet& operator=(const ArraySet& other);
	~ArraySet();

	void insert(const int& element);
	void remove(const int& element);

	const int* getElement(const int& element);

	void print();
};

