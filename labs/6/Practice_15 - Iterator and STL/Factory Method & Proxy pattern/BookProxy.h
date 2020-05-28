#pragma once
#include "Book.hpp"

class BookProxy : public IBook
{
private:
	std::string filename;
	Book* book;

	void checkResource();
public:
	BookProxy(std::string _filename);
	BookProxy(const BookProxy& other);
	BookProxy& operator=(const BookProxy& other);
	~BookProxy();


	int getNumberOfChapters();
	int getNumberOfPages();
	std::vector<std::string> getChapterTitles();

	IBook* clone() const { return new BookProxy(*this); }
};