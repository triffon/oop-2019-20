#include"Node.hpp"
class LinkedStack{
    Node* top;
public:
    LinkedStack();
    void push(int element);
    void pop();
    int peek();
    bool empty();
};