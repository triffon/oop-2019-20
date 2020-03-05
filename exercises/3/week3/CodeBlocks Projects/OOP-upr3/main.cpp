#include<iostream>
#include<cstring>
#include"LinkedStack.h"
#include"ArrayStack.h"
using namespace std;
int main(){
    ArrayStack stk; ///Should work with both ArrayStack and LinkedStack
    char str[10];
    cin >> str;
    int sizeOfString = strlen(str);
    for(int i=0;i<sizeOfString;i++){
        //cout << str[i] << endl;
        stk.push(str[i]);
    }
    for(int i=0;i<sizeOfString;i++){
        char current = stk.peek();
        stk.pop();
        cout << current;
    }

    return 0;
}
