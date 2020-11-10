#ifndef  __STACK_H__
#define  __STACK_H__

#include <iostream>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
#define STACK_SIZE 100
typedef float Element;

class Stack {
private:
	int top;
	int max_size;
	Element* stack;
	

public:
	Stack();
	~Stack();
	void Push(Element item);
	Element Pop();
	bool IsFullS();
	bool IsEmptyS();
};


Stack::Stack() {
	top = -1;
	max_size = STACK_SIZE;
	stack = new Element(max_size);
}

Stack::~Stack() {
	delete(stack);
}

void Stack::Push(Element item) {
	if (IsFullS())
		cout << "Stack is Full" << endl;
	else {
		stack[++top] = item;
    //cout << "stack["<< top<< "]= " << stack[top] << endl;
	}
	}

Element Stack::Pop() {
	if (IsEmptyS()) {
		cout << "Stack is Empty" << endl;
		return (int) 0;
	}
	else 
		return stack[top--];
}

bool Stack::IsEmptyS() {
	if (top == -1)
		return true;
	else
		return false;
}

bool Stack::IsFullS() {
	return (top == max_size - 1);
}



#endif