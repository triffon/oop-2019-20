#pragma once

#include <vector>
#include <string>

#include "ISerializable.h"
#include "ICloneable.h"


class IBook : public ISerializable, public ICloneable<IBook>
{
protected:
	std::string content;

public:
	virtual int getNumberOfChapters() = 0;
	virtual int getNumberOfPages() = 0;
	virtual std::vector<std::string> getChapterTitles() = 0;

	void serialize(std::ostream& out) const override
	{
		out << content << std::endl;
	}

	virtual void deserialize(std::istream& in) override
	{
		while (in.good())
		{
			std::string currentLine;
			std::getline(in, currentLine);
			content += currentLine;
		}
	}

};