#pragma once

template <typename T>
class ICollection
{
	virtual bool member(const T&) const = 0;
	virtual bool add(const T&) = 0;
	virtual bool remove(const T&) = 0;
	virtual size_t getSize() const = 0;
	virtual T& operator [] (int i) = 0;
	virtual const T& operator [] (int i) const = 0;
};