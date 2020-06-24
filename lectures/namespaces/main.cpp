#include <iostream>
//using namespace std;
using std::cout;
using std::clog;

/*
int min(int x, int y) {
    clog << "my min function!\n";
    return x < y ? x : y;
}
*/

/*
int STD_min(int x, int y) {
    ...
}
*/


void min() {
    clog << "test min";
}

namespace myspace {
    using std::cerr;
}

namespace X {
    using namespace std;
}

// !!!
namespace std {
    void myfun() { std::cout << "myfun"; }
}

int main() {
    int min = 4;
  //  cout << min(2, 8);
    X::cout << std::min(2, 8) << X::endl;
  //  cout << min(2, 8);
    myspace::cerr << "hello" << X::endl;
    std::myfun();
    return 0;
}