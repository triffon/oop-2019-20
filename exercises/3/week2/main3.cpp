#include<iostream>
#include<cstring>
#include"Student.h"
using namespace std;
class PositiveRationalNumber{
int chislitel;
int znam;
public:
float getValue(){
    return ((float)chislitel)/znam;
}
float setValue(float value){
    if(value<0){
        cout << "Enter new value" <<endl;
        return getValue();
    }
    value*=100;
    chislitel = value;
    znam = 100;
}
};
int main(){
    PositiveRationalNumber rn;
    rn.setValue(-3.14);
    cout << rn.getValue() << endl;
    return 0;
}
