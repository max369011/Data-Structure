#include <iostream>
using namespace std;

typedef string Element;

typedef struct node {
	node* Lchild;
	node* Rchild;
	Element data;
	Element key;
} tree_node;

class BST {
private:
	tree_node* root;
public:

	BST();
	~BST();
	
	bool searchKey(Element key);
	Element search(Element key);
	tree_node* searchRecursive(tree_node* tree, Element key);
  tree_node* modified_search(Element key);
	void add(Element num, Element data);
	void delete_tree(tree_node* ptr);
	bool isEmpty();
	void inorder(tree_node* ptr);
	void print();
};
