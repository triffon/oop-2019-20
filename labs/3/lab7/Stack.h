//
// Created by tony on 16.04.20 г..
//

#ifndef FMIOOP_STACK_H
#define FMIOOP_STACK_H

template <class T>
class Stack {
    T* data;
    unsigned size;
    unsigned capacity;

    void copy(const Stack& other);
    void clean();
    void resize();
public:
    Stack();
    Stack(int capacity);
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    void push(T toPush);
    T pop();
    T top() const;


    int getSize() const;
    bool empty() const;
};


#endif //FMIOOP_STACK_H
