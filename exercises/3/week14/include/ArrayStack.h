#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include"Stack.h"
#include"Cloneable.h"
// This is an concrete class since all of the functions have implementation thus we can create instances from it
class ArrayStack:public Stack, public Clonable{
    int arr[100];
    int current; ///point to the first free index in the array
public:
    ArrayStack();
    ArrayStack(const ArrayStack& other)=default;
    void push(int element);
    void pop();
    int peek();
    bool empty();
    ArrayStack * clone();
};
#endif // ARRAYSTACK_H
