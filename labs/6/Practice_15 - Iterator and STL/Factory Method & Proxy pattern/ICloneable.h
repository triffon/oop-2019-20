#pragma once

template <typename T>
class ICloneable
{
public:
	virtual T* clone() const = 0;
};