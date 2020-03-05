#include"LinkedStack.hpp"
LinkedStack::LinkedStack(){
        top = nullptr;
}
void LinkedStack::push(int element){
        Node* current = new Node();
        current->data = element;
        current->next = top;

        top = current;
}
void LinkedStack::pop(){
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
}
int LinkedStack::peek(){
        return top->data;
}
bool LinkedStack::empty(){
        return top==nullptr;
}
