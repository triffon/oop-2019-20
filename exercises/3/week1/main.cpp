#include<iostream>
#include<cstring>
using namespace std;
//The sturct is a collection of differnt data
//Its data could be primitive values, other structs and functions
//By default the visibility of its members is public => they can be accessed anywhere
struct faculty{
    char name[10];
};
//The class is the same as the struct except that its members by default are private
class Student{
//These aren't accessible by anyone outside the class
    faculty f;
    int fNum;
    char * name;
//here we add access modifier to change the visibility of the next members
public:
//These members can be accessed by anyone
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
