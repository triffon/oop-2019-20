#include<iostream>
using namespace std;
class Person{
public:
    Person(){
        cout << "constructor" << endl;
    };
    Person(Person& other){
        cout << "copy constructor" << endl;
    };
};
int swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
///Person p1 = p2;
void func(Person p1){
}
int main(){
    Person p2;
    func(p2);
    return 0;
}
