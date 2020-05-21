#ifndef STACK_H
#define STACK_H
// Class with at least one virtual function is called abstract class
// You can't make instances of abstract classes but you can create of concrete classes
// Class with no implmented functions/all functions are virtual is called interface
class Stack{
public:
    virtual void push(int element)=0;
    virtual void pop()=0;
    virtual int peek()=0;
    virtual bool empty()=0;
    virtual ~Stack()=default;
};
#endif /* STACK_H */
