#include <cassert>
#include "lstack.hpp"

// създаване на празен стек 
LinkedStack::LinkedStack() {
    top = nullptr;
}

// проверка за празнота
bool LinkedStack::empty() const {
    return top == nullptr;
}

// включване на елемент
void LinkedStack::push(int x) {
    /*
    StackElement* p = new StackElement;
    p->data = x;
    p->next = top;
    top = p;*/
    // !!! StackElement se = { x, top };
    top = new StackElement{ x, top };
}

// изключване на елемент
int LinkedStack::pop() {
    assert(!empty());
    // запомняме върха на стека и елемента на върха
    int x = peek();
    StackElement* p = top;
    // преместваме top напред във веригата
    top = top->next;
    // изтриваме стария връх на стека
    delete p;
    return x;
}

// поглеждане на последно включения елемент
int LinkedStack::peek() const {
    assert(!empty());
    return top->data;
}

LinkedStack::~LinkedStack() {
    while (!empty())
        pop();
}