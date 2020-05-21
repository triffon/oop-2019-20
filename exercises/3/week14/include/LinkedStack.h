#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include"Node.h"
#include"Stack.h"
// This is an concrete class since all of the functions have implementation thus we can create instances from it
class LinkedStack:public Stack{
    Node* top;
public:
    LinkedStack();
    void push(int element);
    void pop();
    int peek();
    bool empty();
};
#endif // LINKEDSTACK_H
