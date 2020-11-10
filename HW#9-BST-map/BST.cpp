#include <iostream>
#include <string.h>
#include "BST.h"
using namespace std;

BST::BST() {
	root = NULL;
}


BST::~BST() {
	delete_tree(root);
	root = NULL;
}


void BST::delete_tree(tree_node* ptr) {
	if (ptr) {
		delete_tree(ptr->Lchild);
		delete_tree(ptr->Rchild);
		delete(ptr);
	}
}


bool BST::isEmpty() {
	return (root == NULL);
}


bool BST::searchKey(Element key) {
  if(searchRecursive(root, key)!=NULL)
    return true;
  else
    return false;
}


Element BST::search(Element key) {
  tree_node* node;
  node = searchRecursive(root, key);
  return node->data;
}


tree_node* BST::searchRecursive(tree_node* tree, Element key) { 
    if (tree == NULL)
        return NULL;
    
    if (key.compare(tree->key) == 0)
        return tree;
    else if (key.compare(tree->key) < 0)
        return searchRecursive(tree->Lchild, key);  // return this value
    else
        return searchRecursive(tree->Rchild, key); // return this value

    return NULL;
}


/*
returns NULL, if the tree is empty or if the key is present. 
  Otherwise, it returns a pointer to the last node of the tree that was encountered during search
**/
tree_node* BST::modified_search(Element key) { 
  tree_node *tree = root; 
  while(tree){ 
    if(key == tree->key) return NULL; // key is present 
    else if(key < tree->key) 
      if(tree->Lchild == NULL) 
        return tree; 
      else 
        tree = tree->Lchild; 
    else                               // key > tree->key 
      if(tree->Rchild == NULL) 
        return tree; 
    else 
      tree = tree->Rchild; 
  } 
    return NULL; 
}


void BST::add(Element key, Element data) { 
  tree_node *ptr = NULL, *parent = NULL; 
  parent = modified_search(key); 
  
  //if num is not in the tree
  if(parent || isEmpty()) {  
  ptr = new tree_node; 
 
  ptr->key = key;
  ptr->data = data;
  ptr->Lchild = ptr->Rchild = NULL; 
  
  //if tree is empty
  if(isEmpty()) 
    root = ptr; 
  //if tree is not empty
  else { 
    if(key < parent->key) 
      parent->Lchild = ptr; 
    else 
      parent->Rchild = ptr; 
    } 
  } else if(parent == NULL) {
    cout << key <<  " is already in the tree." << endl;
  }
}


void BST::inorder(tree_node* ptr) {
	if (ptr) {
		inorder(ptr->Lchild);
		cout << "(" << ptr->key << ","<<  ptr->data << ")"<<endl;
		inorder(ptr->Rchild);
	}
}


void BST::print() {
	inorder(root);
}
