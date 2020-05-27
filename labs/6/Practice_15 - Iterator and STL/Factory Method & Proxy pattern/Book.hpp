#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "IBook.hpp"

class Book : public IBook
{
public:
	// Slow operation!
	Book(std::string filename)
	{
		std::ifstream in(filename);
		deserialize(in);
		Sleep(2000);
		std::cout << "Book loaded from " << filename << std::endl;
	}

	// Fast operations!
	int getNumberOfChapters()  override { return 15; }
	int getNumberOfPages()  override { return 3200; }
	std::vector<std::string> getChapterTitles()  override { return { "Title 01","Title 02" ,"Title 03" ,"Title 04" ,"Title 05" }; }

	IBook* clone() const { return new Book(*this); }
};