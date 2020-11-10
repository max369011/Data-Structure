#include <iostream>
#include "stack.h"

using namespace std;


Stack_List::Stack_List() {
	top = NULL;
}

Stack_List::~Stack_List() {
	delete_list(top);
}

void Stack_List::delete_list(nodePtr* node_ptr) {  
	if (node_ptr != NULL) {
		delete(node_ptr->link);
		delete(node_ptr);
	}
}

void Stack_List::push(Element data) {
	nodePtr* new_node = new node;
	new_node->data = data;
	new_node->link = NULL;

	if (top == NULL) 
		new_node->link = NULL;
	else 
		new_node->link = top;			//link last in Stack_List with new_node
	
	top = new_node;
}

Element Stack_List::pop() {
	nodePtr* cur = top;

	if (top == NULL) {
		cout << "Stack is already Empty" << endl;
		return (Element) 0;
	} else {
		top = cur->link;
	}
	return cur->data;
}

void Stack_List::print() {
	nodePtr* cur = NULL;
	for (cur = top; cur != NULL; cur = cur->link) {
		cout << cur->data << "->";
	}
	cout << "NULL" << endl;
}

bool Stack_List::isEmpty() {
  if(top == NULL)
    return true;
  else 
    return false;
}