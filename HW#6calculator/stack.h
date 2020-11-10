#ifndef  __STACK_H__
#define  __STACK_H__

#include <iostream>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
#define STACK_SIZE 100

template <class T>
class Stack {
private:
	int max_size;
	T* stack;
	

public:
	int top;
	Stack();
	~Stack();
	void Push(T item);
	T Pop();
	bool IsFullS();
	bool IsEmptyS();
	T getTop();
	T peek();
};

template <class T>
  Stack<T>::Stack() {
	top = -1;
	max_size = STACK_SIZE;
	stack = new T(max_size);
}

template <class T>
  Stack<T>::~Stack() {
	delete(stack);
}

template <class T>
void Stack<T>::Push(T item) {
	if (IsFullS())
		cout << "Stack is Full" << endl;
	else {
		stack[++top] = item;
    //cout << "stack["<< top<< "]= " << stack[top] << endl;
	}
	}

template <class T>
T Stack<T>::Pop() {
	if (IsEmptyS()) {
		cout << "Stack is Empty" << endl;
		return (int) 0;
	}
	else {
		return stack[top--];
}
}

template <class T>
bool Stack<T>::IsEmptyS() {
	if (top == -1)
		return true;
	else
		return false;
}

template <class T>
bool Stack<T>::IsFullS() {
	return (top == max_size - 1);
}

template <class T>
T Stack<T>::getTop() {
  return top;
}

template <class T>
T Stack<T>::peek() {
  return stack[top];
}
#endif