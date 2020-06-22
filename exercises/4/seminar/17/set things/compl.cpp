#include <iostream>
using namespace std;

int* arr = {1, 2, 3, 4, 5};
int siz = 5;

void al1(int j) {
    cout<< arr[j]<< endl; // arr + sizeof(int)*index
}

void al2(int j) {
    int i = 0;
    for(; i< j; ++i) {} // ....
    cout<< arr[i]<< endl;
}

int main() {


    return 0;
}
