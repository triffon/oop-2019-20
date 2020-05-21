#include "LinkedStack.h"
#include<iostream>
#include<assert.h>
#include<ArrayStack.h>
using namespace std;

void givenEmptyWhenPeekThenCrash(){
	ArrayStack a;
	cout <<	a.peek();
}

void givenNotEmptyWhenPeekThenReturn(){
	ArrayStack a;
	a.push(2);
	assert(a.peek()==2);
}
class ArrayStackStub:ArrayStack{
public:
	void push(){};
	bool empty(){ return false;}
	int peek(){return 15;}
};
int averageOfTops(ArrayStackStub a1, ArrayStackStub a2){
	return (a1.peek()+a2.peek())/2;
}
void givenTwoNonEmptyArrayStackReturnAverageOfTops(){
	ArrayStackStub a;
	ArrayStackStub b;
	assert(averageOfTops(a,b)==15);
}
/// Simple functions to be used for the demo of abstract classes and interfaces
void printStack(Stack * s){
	while(!s->empty()){
		cout << s->peek() << endl;
		s->pop();
	}
}
void fillStack(Stack * s){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int current;
		cin >> current;
		s->push(current);
	}
}
/// The interfaces are like a contract to the world telling what a specific class can do
/// Every class that implements/inherits Stack can be used in places where the abstraction Stack is required
void stackDemo(){
	Stack * s1 = new ArrayStack();
	fillStack(s1);
	printStack(s1);
	Stack * s2 = new LinkedStack();
	fillStack(s2);
	printStack(s2);
}
int main(){
	return 0;
}
