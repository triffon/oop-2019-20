#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;

int main() {
    Stack<int> tt;

    tt.push(1);
    tt.push(3);
    tt.push(5);
    cout << tt.pop() << endl;
    cout << tt.top() << endl;
    cout << tt.size() << endl;
    cout << tt.empty() << endl;

    cout << endl;

    Queue<int> yy;

    yy.push(1);
    yy.push(3);
    yy.push(5);
    cout << yy.pop() << endl;
    cout << yy.top() << endl;
    cout << yy.size() << endl;
    cout << yy.empty() << endl;

    return 0;
}
