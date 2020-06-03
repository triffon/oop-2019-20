#include <iostream>
using namespace std;

int main () {
    float a = 5;

    float b = 10 / 4;

    float c = 10.0 / 4;

    float d = (double)10 / 4;

    float e = static_cast<double>(10) / 4;

    cout<< a<< " "<< b<< " "<< c<< " "<< d<< " "<< e<< endl;

    return 0;
}
