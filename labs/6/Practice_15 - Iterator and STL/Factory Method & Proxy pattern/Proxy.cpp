#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

#include "IBook.hpp"
#include "IBookFileFactory.hpp"
#include "BookFileFactory.hpp"
#include "Library.h"
#include "BookProxyFileFactory.hpp"

void testLibraryWithBook();
void testLibraryWithBookProxy();
int main()
{
	testLibraryWithBook();
	Sleep(1000);
	std::cout << std::endl << std::endl;
	testLibraryWithBookProxy();
}
void testLibraryWithBook()
{
	std::cout << "Starting test for library with books. Loading 4 books..." << std::endl;

	IBookFileFactory* bookFactory = new BookFileFactory({ "test01.txt","test01.txt" ,"test01.txt" ,"test01.txt" });
	Library simpleLibrary = Library::loadFromFiles(bookFactory);

	simpleLibrary.add(new Book("test01.txt"));
	std::cout << "Simple Library pages for index 4: " << simpleLibrary.getNumberOfPages(4) << std::endl;
	std::cout << "Library test with books finished." << std::endl;
}
void testLibraryWithBookProxy()
{
	std::cout << "Starting test for library with proxy. Loading 500 books..." << std::endl;
	std::vector<std::string> filenames;
	for (size_t i = 0; i < 500; i++)
	{
		filenames.push_back("test01.txt");
	}

	IBookFileFactory* proxyFactory = new BookProxyFileFactory(filenames);
	Library library = Library::loadFromFiles(proxyFactory);
	std::cout << library.getNumberOfChapters(4) << std::endl;
	// Initialize library using BookProxy.

	std::cout << "Library test with proxy finished." << std::endl;

}
