#include <iostream>
using namespace std;

void f() {
    throw 5;
}

void g() {
    throw "wrong";
}

int main() {
    try {
        g();
        f();
    } catch(int x) {
        cout<< "error code: "<< x;
    } catch(const char* error) {
        cout<< error<< endl;
    }
}
