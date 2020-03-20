#pragma once
#include <cstring>

char* copyDyn(const char* str) {
	char* newStr = new char[strlen(str) + 1];
	strcpy(newStr, str);

	return newStr;
}