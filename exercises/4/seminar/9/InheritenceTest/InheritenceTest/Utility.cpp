#include "Utility.h"

int Utility::strlen(const char* str) {
	int len = 0;
	for (; str[len] != '\0'; ++len);
	return len;
}

void Utility::strcpy(char* destination, const char* source) {
    int i = 0;
    for (; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
}