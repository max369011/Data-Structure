#include <iostream>
using namespace std;

typedef string Element;

typedef struct node {
	Element data;
	node* link;
} nodePtr;

class Stack_List {

private:
	nodePtr* top;
public:
	Stack_List();
	~Stack_List();
	void delete_list(nodePtr* node_ptr);
	void push(Element data);
	Element pop();
	void print();
  bool isEmpty();
};

