#include <cassert>
#include "rstack.hpp"

const int EMPTY_STACK = -1;
const unsigned INITIAL_CAPACITY = 10;

// създаване на празен стек 
ResizingStack::ResizingStack() {
    top = EMPTY_STACK;
    capacity = INITIAL_CAPACITY;
    a = new int[INITIAL_CAPACITY];
}

// проверка дали стекът е пълен
bool ResizingStack::full() const {
    return top == capacity - 1;
}

// проверка за празнота
bool ResizingStack::empty() const {
    return top == EMPTY_STACK;
}

// включване на елемент
void ResizingStack::push(int x) {
    if (full())
        resize();
    a[++top] = x;
    // !!! top++ = 4;
    // OK: ++top = 4;
}

// изключване на елемент
int ResizingStack::pop() {
    assert(!empty()); // не искаме да позволяваме изключване на елемент от празен стек
    return a[top--];
}

// поглеждане на последно включения елемент
int ResizingStack::peek() const {
    assert(!empty()); // не искаме да позволяваме поглеждане на елемент от празен стек
    return a[top];
}

// разширяване на стека
void ResizingStack::resize() {
    // пас
}