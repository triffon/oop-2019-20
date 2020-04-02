#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class MyString {
    char* symbols;

public:
    MyString() {
        symbols = nullptr;
    }

    MyString(const MyString& origin) {
        symbols = new char[strlen(origin.getSymbols())];
        strcpy(symbols, origin.getSymbols());
    }

    const char* getSymbols() const {
        return symbols;
    }

    MyString& operator=(const MyString& origin) {
        if (this != &origin) {
            delete[] symbols;
            symbols = new char[strlen(origin.getSymbols()) + 1];
            strcpy(symbols, origin.getSymbols());
        }

        return *this;
    }

    MyString& operator=(const char* text) {
        delete[] symbols;
        symbols = new char[strlen(text)];
        strcpy(symbols, text);

        return *this;
    }

    void print() {
        if (symbols) {
            cout << symbols << endl;
        }
    }

    ~MyString() {
        delete[] symbols;
    }

};

int main() {
    MyString text;
    cout << "Text1: \n";
    text.print();
    text = "Hello world!";
    cout << "Text1: \n";
    text.print();

    MyString text2(text);
    cout << "Text2: \n";
    text2.print();
    text2 = "Hello Sun!";
    cout << "Text2: \n";
    text2.print();


    MyString text3;
    cout << "Text3: \n";
    text3.print();
    text3 = text2;
    cout << "Text3: \n";
    text3.print();

    delete &text;
    delete &text2;
    delete &text3;

    return 0;
}
