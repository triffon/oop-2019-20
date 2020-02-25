#include<iostream>
#include<cstring>
using namespace std;
struct faculty{
    char name[10];
};
class Student{
    faculty f;
    int fNum;
    char * name;
public:
    Student(){};
    Student(int _fNum,const char * _name){
        if(fNum >= 80000 ){
            fNum = _fNum;
        }else{
            fNum = 80000;
        }
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
    }
    ~Student(){
        cout << "destructor called" << endl;
        delete[] name;
    }
    char * getName(){
        return name;
    }
};
int main(){
    Student * s = new Student(81712,"Kamen");
    delete s;
    return 0;
}
