#pragma once
#include <istream>
#include <ostream>

class ISerializable
{
public:
	virtual void deserialize(std::istream& in) = 0;
	virtual void serialize(std::ostream& out) const = 0;
};