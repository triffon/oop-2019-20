#include "Library.h"
#include <iostream>

void Library::copyBooks(std::vector<IBook*> _books)
{
	for (size_t i = 0; i < _books.size(); i++)
	{
		books.push_back(_books[i]->clone());
	}
}

void Library::clean()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		delete books[i];
	}
}

Library Library::loadFromFiles(IBookFileFactory* fileFactory)
{
	Library result;
	result.books = fileFactory->createAll();

	std::cout << "Loading finished." << std::endl;
	return result;

}

Library::Library(std::vector<IBook*> _books)
{
	copyBooks(_books);
}
Library::Library(const Library& other)
{
	copyBooks(other.books);
}

Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		clean();
		copyBooks(other.books);
	}
	return *this;
}

Library::~Library()
{
	clean();
}

void Library::add(IBook* book)
{
	books.push_back(book);
}

int Library::getNumberOfChapters(int index) const
{
	return books[index]->getNumberOfChapters();
}

int Library::getNumberOfPages(int index) const
{
	return books[index]->getNumberOfPages();
}

std::vector<std::string> Library::getChapterTitles(int index) const
{
	return books[index]->getChapterTitles();
}
