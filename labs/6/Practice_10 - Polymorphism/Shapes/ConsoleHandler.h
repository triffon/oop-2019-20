#pragma once
#include "ShapeContainer.h"
#include <string>

class ConsoleHandler
{
public:
	ConsoleHandler(std::string fileName);

public:
	void start();

private:
	ShapeContainer shapes;
};

