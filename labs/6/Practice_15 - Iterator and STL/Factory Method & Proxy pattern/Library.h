#pragma once
#include <vector>
#include "IBookFileFactory.hpp"

class Library
{
private:
	std::vector<IBook*> books;

	void copyBooks(std::vector<IBook*> _books);
	void clean();
public:
	static Library loadFromFiles(IBookFileFactory* fileFactory);

	Library(std::vector<IBook*> _books = {});
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

public:
	void add(IBook* book);

	int getNumberOfChapters(int index) const;
	int getNumberOfPages(int index) const;
	std::vector<std::string> getChapterTitles(int index) const;
};