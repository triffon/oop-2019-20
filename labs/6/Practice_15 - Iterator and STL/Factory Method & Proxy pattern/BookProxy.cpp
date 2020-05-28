#include "BookProxy.h"

void BookProxy::checkResource()
{
	if (book == nullptr)
	{
		book = new Book(filename);
	}
}

BookProxy::BookProxy(std::string _filename) : book(nullptr), filename(_filename)
{
}

BookProxy::BookProxy(const BookProxy& other)
{
	filename = other.filename;
	if (other.book != nullptr)
	{
		book = static_cast<Book*>(other.book->clone());
	}
}

BookProxy& BookProxy::operator=(const BookProxy& other)
{
	if (this != &other)
	{
		delete book;
		book = static_cast<Book*>(other.book->clone());
		filename = other.filename;
	}
	return *this;
}

BookProxy::~BookProxy()
{
	delete book;
}

int BookProxy::getNumberOfChapters()
{
	checkResource();
	return book->getNumberOfChapters();
}

int BookProxy::getNumberOfPages()
{
	checkResource();
	return book->getNumberOfPages();
}

std::vector<std::string> BookProxy::getChapterTitles()
{
	checkResource();
	return book->getChapterTitles();
}
