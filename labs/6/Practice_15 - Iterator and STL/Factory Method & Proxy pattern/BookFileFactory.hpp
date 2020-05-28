#pragma once
#include "IBookFileFactory.hpp"
#include "Book.hpp"

class BookFileFactory : public IBookFileFactory
{
public:
	BookFileFactory(std::vector<std::string> filenames) :IBookFileFactory(filenames) {	}

	virtual std::vector<IBook*> createAll() const override
	{
		std::vector<IBook*> books;
		for (auto& filename : filenames)
		{
			books.push_back(create(filename));
		}

		return books;
	}

	virtual IBook* create(std::string filename) const override
	{
		return new Book(filename);
	}
};