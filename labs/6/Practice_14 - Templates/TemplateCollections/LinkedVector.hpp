#pragma once

#include "ICollection.h"

template<typename T>
struct LinkedNode
{
	T data;
	LinkedNode* next;

	LinkedNode(T _data, LinkedNode* _next = nullptr) : data(_data), next(_next) {}
};

template<typename T>
class LinkedVector : public ICollection<T>
{
public:
	bool member(const T&) const;
	bool add(const T&);
	bool remove(const T&);
	size_t getSize() const;
	T& operator [] (int i);
	const T& operator [] (int i) const;
	void print() const;

	//TODO: Big 4

public:
	LinkedVector();

private:
	bool removeNode(LinkedNode<T>* node);
	LinkedNode<T>* getNodeFromIndex(int index) const;

private:
	LinkedNode<T>* head;
};

template<typename T>
inline void LinkedVector<T>::print() const
{
	LinkedNode<T>* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline LinkedVector<T>::LinkedVector() : head(nullptr) {	}

template<typename T>
inline bool LinkedVector<T>::member(const T& data) const
{
	if (head == nullptr)
	{
		return false;
	}

	LinkedNode<T>* current = head;

	while (current->next != nullptr)
	{
		if (current->data == data)
		{
			return true;
		}

		current = current->next;
	}

	return false;
}

template<typename T>
inline bool LinkedVector<T>::add(const T& data)
{
	if (head == nullptr)
	{
		head = new LinkedNode<T>(data);
		return true;
	}

	LinkedNode<T>* current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = new LinkedNode<T>(data);

	return true;
}

template<typename T>
inline bool LinkedVector<T>::remove(const T& data)
{
	if (head == nullptr)
	{
		return false;
	}

	if (head->data == data)
	{
		LinkedNode<T>* newHead = head->next;
		delete head;
		head = newHead;
		return true;
	}

	LinkedNode<T>* current = head;

	while (current->next != nullptr)
	{
		if (current->next->data == data)
		{
			LinkedNode<T>* tmp = current->next;
			current->next = tmp->next;
			delete tmp;
			return true;
		}

		current = current->next;
	}

	return false;
}

template<typename T>
inline bool LinkedVector<T>::removeNode(LinkedNode<T>* node)
{
	LinkedNode<T>* tmp = node->next;
	node->next = node->next->next;
	delete tmp;
	return true;
}

template<typename T>
inline LinkedNode<T>* LinkedVector<T>::getNodeFromIndex(int index) const
{
	LinkedNode<T>* current = head;
	while (index > 0 && current != nullptr)
	{
		current = current->next;
	}

	return current;
}

template<typename T>
inline size_t LinkedVector<T>::getSize() const
{
	// TODO: while loop + counter
	return size_t();
}

template<typename T>
inline T& LinkedVector<T>::operator[](int i)
{
	LinkedNode<T>* node = getNodeFromIndex(i);
	if (node == nullptr)
	{
		throw std::out_of_range("Invalid index.");
	}

	return node->data;
}

template<typename T>
inline const T& LinkedVector<T>::operator[](int i) const
{
	// TODO: Same as operator[]
	return head->data;
}
