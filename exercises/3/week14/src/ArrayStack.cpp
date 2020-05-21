#include "ArrayStack.h"
ArrayStack::ArrayStack(){
    current = 0;
}
void ArrayStack::push(int element){
    arr[current] = element;
    current++;
}
ArrayStack * ArrayStack::clone(){
	return new ArrayStack(*this);
};

void ArrayStack::pop(){
    current--;
}
int ArrayStack::peek(){
    return arr[current-1];
}
bool ArrayStack::empty(){
    return current==0;
}
