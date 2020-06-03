#include<iostream>
#include<cstring>
using namespace std;
//This is forward declaration
//It tells the compiler that such class exists and we will supply it later
//We use it to deal with cyclic dependencies like this:
//Author requires Book which requires Author which requires Book
class Book;
class Author{
    char name[10];
    Book* books;
};
//Here we actually initialize the class Book
class Book{
    char name[10];
    Author* a;
};
int main(){
    return 0;
}
