#include <iostream>
using namespace std;

int strlen(const char* str) {
    int i = 0;
    for(; str[i] != '\0'; ++i);
    return i;
}

void strcpy(char* destination, const char* source) {
    int i = 0;
    for(; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
}

class String {
    char* data;
    int length;

public:
    String(const char* data) {}
    String(const String& str) = delete;
    String& operator=(const String& str) = delete;
    ~String() {}
};

int main () {

    String s1("str1"), s2("str2");

    cout<< s1.getData()<< " "<< s2.getData()<< endl;

    return 0;
}
