#include <cassert>
#include "stack.hpp"

const int EMPTY_STACK = -1;

// създаване на празен стек 
Stack::Stack() {
    top = EMPTY_STACK;
}

// проверка дали стекът е пълен
bool Stack::full() const {
    return top == MAX_STACK - 1;
}

// проверка за празнота
bool Stack::empty() const {
    return top == EMPTY_STACK;
}

// включване на елемент
void Stack::push(int x) {
    assert(!full());
    a[++top] = x;
    // !!! top++ = 4;
    // OK: ++top = 4;
}

// изключване на елемент
int Stack::pop() {
    assert(!empty()); // не искаме да позволяваме изключване на елемент от празен стек
    return a[top--];
}

// поглеждане на последно включения елемент
int Stack::peek() const {
    assert(!empty()); // не искаме да позволяваме поглеждане на елемент от празен стек
    return a[top];
}