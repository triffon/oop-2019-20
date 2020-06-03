#include<iostream>
#include<cstring>
#include"Student.h"
using namespace std;
//We could create a rational number abstraction using this class
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
//However we could also use the following class
class PositiveRationalNumber2{
float value;
public:
void setValue(float f){
	this->value = f;
}
float getValue(){
	return value;
}
};
//These two classes are realization of the same abstraction
//They only differ internally
int main(){
    PositiveRationalNumber rn;
    rn.setValue(-3.14);
    cout << rn.getValue() << endl;
    return 0;
}
