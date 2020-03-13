#include <iostream>
#include <cassert>
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

// strlen, strcpy, strcat
class String {

private:
    char* data;
    int length;

    void copyData(const String& str) {
        length = str.length;
        this->data = new char[length + 1];
        strcpy(this->data, str.data);
    }

    void clearData() {
        delete [] data;
    }

public:
    // resource aquisition is initialization
    String(const char* data = ""): data(NULL), length(0) {
        length = strlen(data);
        this->data = new char[length + 1];
        strcpy(this->data, data);
    }

    String(const String& str) {
        copyData(str);
    }

    String& operator=(const String& str) {
        if(this == &str) {
            return *this;
        }
        clearData();
        copyData(str);

        return *this;
    }

    ~String() {
        clearData();
    }

    void strcat(const String& str) {
        char* newData = new char[length + str.length + 1];
        for(int i = 0; data[i] != '\0'; ++i) {
            newData[i] = data[i];
        }
        cout<< length<< endl;
        for(int i = 0; str.data[i] != '\0'; ++i) {
            newData[i + length] = str.data[i];
        }
        newData[length + str.length] = '\0';

        delete [] data;

        data = newData;
        length = length + str.length;
    }

    static String strcat(const String& s1, const String& s2) {
        String result;
        result.strcat(s1);
        result.strcat(s2);
        return result;
    }

    int getLength() const {
        return length;
    }

    const char* getData() const {
        return data;
    }
};

int main () {
    String s1("str1"), s2("str2");

    s1.strcat(s2);
    cout<< s1.getData()<< endl;

    String s3 = String::strcat(s1, s2);
    cout<< s3.getData()<< endl;

    return 0;
}
