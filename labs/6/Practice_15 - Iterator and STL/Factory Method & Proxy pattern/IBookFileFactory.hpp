#pragma once

#include <vector>
#include <string>

#include "IBook.hpp"

class IBookFileFactory
{
protected:
	std::vector < std::string> filenames;
	IBookFileFactory(std::vector<std::string> _filenames) : filenames(_filenames) {	}

public:
	virtual std::vector<IBook*> createAll() const = 0;
	virtual IBook* create(std::string filename) const = 0;
};
