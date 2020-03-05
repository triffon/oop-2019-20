#include"Student.h"
#include<iostream>
#include<cstring>
using namespace std;
Student::Student(){};
Student::Student(int _fNum,const char * _name){
        if(fNum >= 80000 ){
            fNum = _fNum;
        }else{
            fNum = 80000;
        }
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
}
Student::Student(const Student& other){
        cout << "copy constr called" << endl;
        f=other.f;
        fNum=other.fNum;
        name = new char[strlen(other.name)];
        strcpy(name,other.name);
    }
Student& Student::operator=(const Student& other){
        if(this!=&other){
            cout << "operator= called" << endl;
            f=other.f;
            fNum=other.fNum;
            delete[] name;
            name = new char[strlen(other.name)];
            strcpy(name,other.name);
        }
        return *this;
    }
Student::~Student(){
    cout << "destructor called" << endl;
    delete[] name;
}
char * Student::getName(){
    return name;
}
