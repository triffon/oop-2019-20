#include<iostream>
#include<cstring>
using namespace std;
class Book;
class Author{
    char name[10];
    Book* books;
};
class Book{
    char name[10];
    Author* a;
};
int main(){
    return 0;
}
