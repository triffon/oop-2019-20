#pragma once

template <typename U>
class Container {
public:
    Container() {}
    virtual void push(U) = 0;
    virtual U pop() = 0;
    virtual U top() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};


