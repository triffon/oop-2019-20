#include <iostream>
//#include <vector>
using namespace std;

template<typename T>
class v2dWrapper {
    T data;

    v2dWrapper(v2dWrapper&& other): data(std::move(other.data)) {}
};

int main() {

    return 0;
}
