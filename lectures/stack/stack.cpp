#include "stack.hpp"

const int EMPTY_STACK = -1;

// създаване на празен стек 
Stack::Stack() {
    top = EMPTY_STACK;
}

// проверка за празнота
bool Stack::empty() const {
    return top == EMPTY_STACK;
}

// включване на елемент
void Stack::push(int x) {
    a[++top] = x;
    // !!! top++ = 4;
    // OK: ++top = 4;
}

// изключване на елемент
int Stack::pop() {
    return a[top--];
}

// поглеждане на последно включения елемент
int Stack::peek() const {
    return a[top];
}