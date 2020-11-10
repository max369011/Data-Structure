#include <iostream>
using namespace std;

typedef string Element;

typedef struct node {
	node* Lchild;
	node* Rchild;
	Element data;
	int key;
} tree_node;

class BST {
private:
	tree_node* root;
public:

	BST();
	~BST();
	
  tree_node* modified_search(int key);
	void add(int num, Element item);
	void remove(int key);
	tree_node* deleteNode(tree_node* node, int key);
	void delete_tree(tree_node* ptr);
	bool isEmpty();
	void inorder(tree_node* ptr);
	void print();
};
