#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include"Node.h"
class LinkedStack{
    Node* top;
public:
    LinkedStack();
    void push(int element);
    void pop();
    int peek();
    bool empty();
};
#endif // LINKEDSTACK_H
