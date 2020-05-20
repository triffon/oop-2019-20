#ifndef __LSTACK_HPP
#define __LSTACK_HPP

#include <cassert>

#include "abstract_stack.hpp"

template <typename T>
struct StackElement {
    T data;
    StackElement* next;
};

template <typename T>
class LinkedStack : public AbstractStack<T> {
    StackElement<T>* top; // указател към двойната кутия, която е на върха на стека

    // friend struct StackElement<T>;
    void copy(LinkedStack const&);

    void erase();
public:
    // създаване на празен стек 
    LinkedStack();

    // унищожаване на стек
    ~LinkedStack();

    // конструктор за копиране
    LinkedStack(LinkedStack const&);

    // операция за присвояване
    LinkedStack& operator=(LinkedStack const&);

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(T const& x);

    // изключване на елемент
    T pop();

    // поглеждане на последно включения елемент
    T peek() const;
};

// създаване на празен стек
template <typename T>
LinkedStack<T>::LinkedStack() {
    top = nullptr;
}

// проверка за празнота
template <typename T>
bool LinkedStack<T>::empty() const {
    return top == nullptr;
}

// включване на елемент
template <typename T>
void LinkedStack<T>::push(T const& x) {
    /*
    StackElement* p = new StackElement;
    p->data = x;
    p->next = top;
    top = p;*/
    // !!! StackElement se = { x, top };
    top = new StackElement<T>{ x, top };
}

// изключване на елемент
template <typename T>
T LinkedStack<T>::pop() {
    assert(!empty());
    // запомняме върха на стека и елемента на върха
    int x = peek();
    StackElement<T>* p = top;
    // преместваме top напред във веригата
    top = top->next;
    // изтриваме стария връх на стека
    delete p;
    return x;
}

// поглеждане на последно включения елемент
template <typename T>
T LinkedStack<T>::peek() const {
    assert(!empty());
    return top->data;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    erase();
}

template <typename T>
void LinkedStack<T>::erase() {
    while (!empty())
        pop();
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack const& other) {
    copy(other);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack const& other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
void LinkedStack<T>::copy(LinkedStack const& other) {
    /*
    while (!empty())
        push(other.pop());
    */
   if (other.top == nullptr) {
       top = nullptr;
   } else {
       // other.top != nullptr
       StackElement<T> *lastCopied = top = new StackElement{other.top->data}, *copyFrom = other.top->next;
       while (copyFrom != nullptr) {
           lastCopied = lastCopied->next = new StackElement{copyFrom->data};
           copyFrom = copyFrom->next;
       }
       // copyFrom == nullptr
       // приключваме веригата
       lastCopied->next = nullptr;
   }
}
#endif