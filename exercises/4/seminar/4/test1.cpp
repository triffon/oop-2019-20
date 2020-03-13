
#include <iostream>
using namespace std;

struct Str {
    char* data;

    Str(const char* data) {
        int len = 0;
        for(; data[len] != '\0'; ++len);
        this->data = new char[len + 1];
        for(int i = 0; i< len+1; ++i) {
            this->data[i] = data[i];
        }
    }

    ~Str() {
        delete [] data;
    };
};

int main() {
    Str str1("asdf");
    cout<< str1.data<< endl;
    if(true) {
        Str str2(str1);
    }
    cout<< str1.data<< endl;

    return 0;
}
