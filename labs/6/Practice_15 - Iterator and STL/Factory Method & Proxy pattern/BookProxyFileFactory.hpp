#pragma once
#include "BookFileFactory.hpp"
#include "BookProxy.h"

class BookProxyFileFactory : public BookFileFactory
{

public:
	BookProxyFileFactory(std::vector<std::string> _filenames) : BookFileFactory(_filenames) {	}
	virtual IBook* create(std::string filename) const
	{
		return new BookProxy(filename);
	}
};