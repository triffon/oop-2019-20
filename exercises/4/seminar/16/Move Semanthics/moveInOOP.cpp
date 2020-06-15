#include <iostream>
//#include <string>
using namespace std;

class vec {
    string name;
    int* data;
    int sz;

public:
    vec(int sz = 0, const string& name = ""): data(new int[sz]), sz(sz), name(name) {
        cout<< "dc"<< endl;
    }
    vec(const vec& other): data(new int[other.sz]), sz(other.sz), name(name) {
        cout<< "copying"<< endl;
        for(int i = 0; i< sz; ++i) {
            data[i] = other.data[i];
        }
    }
    vec(vec&& other): data(other.data), sz(other.sz), name(std::move(other.name)) {
        cout<< "moving"<< endl;
        other.data = NULL;
        other.sz = 0;
    }
    vec& operator=(const vec& other) {
        cout<< "copying"<< endl;
        if(this == &other) {
            return *this;
        }

        delete [] data;
        sz = other.sz;

        for(int i = 0; i< sz; ++i) {
            data[i] = other.data[i];
        }

        name = other.name;
    }
    vec& operator=(vec&& other) {
        cout<< "moving"<< endl;
        if(this == &other) {
            return *this;
        }

        data = other.data;
        sz = other.sz;
        name = std::move(other.name);
        other.data = NULL;
        other.sz = 0;
    }

    ~vec() {
        delete[] data;
    }

    vec even() {
        int evenSize = 0;
        for(int i = 0; i< sz; ++i) {
            if(data[i] % 2 == 0) {
                ++evenSize;
            }
        }
        vec evenVec(evenSize);
        int cnt = 0;
        for(int i = 0; i< sz; ++i) {
            if(data[i] % 2 == 0) {
                evenVec[cnt++] = data[i];
            }
        }

        return evenVec; //std::move(evenVec);
    }

    const int& getSz() {
        return sz;
    }

    const string& getName() {
        return name;
    }

    int& operator[](int index) {
        return data[index];
    }
};

int main() {

    const int testSize = 10;

    vec v1(testSize);
    for(int i = 0; i< testSize; ++i) {
        v1[i] = i+1;
    }

    vec v2(v1.even());
    for(int i = 0; i< v2.getSz(); ++i) {
        cout<< v2[i]<< " ";
    }
    cout<< endl;


    return 0;
}
