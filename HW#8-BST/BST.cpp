#include <iostream>
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


/*
returns NULL, if the tree is empty or if the key is present. 
  Otherwise, it returns a pointer to the last node of the tree that was encountered during search
**/
tree_node* BST::modified_search(int key) { 
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
      tree = tree->Rchild; } 
    return NULL; 
  
}


void BST::add(int num, Element item) { 
  tree_node *ptr = NULL, *parent = NULL; 
  parent = modified_search(num); 
  
  //if num is not in the tree
  if(parent || isEmpty()) {  
  ptr = new tree_node; 
 
  ptr->key = num;
  ptr->data = item;
  ptr->Lchild = ptr->Rchild = NULL; 
  
  //if tree is empty
  if(isEmpty()) 
    root = ptr; 
  //if tree is not empty
  else { 
    if(num < parent->key) 
      parent->Lchild = ptr; 
    else 
      parent->Rchild = ptr; 
    } 
  } else if(parent == NULL) {
    cout << num <<  " is already in the tree." << endl;
  }
}


void BST::remove(int key) {
 root = deleteNode(root, key);
}


tree_node* BST::deleteNode(tree_node* tree, int key) {
  
  //if key is not in the tree
  if(modified_search(key)) { 
    cout<< key << " is not in the tree." << endl;
    return tree;
  }
  
  //if tree is empty
  if(!tree) return NULL;    
  
  //Recursion until specified parent is found
  else if(key < tree->key)
    tree->Lchild = deleteNode(tree->Lchild, key);
  else if(key > tree->key) 
    tree->Rchild = deleteNode(tree->Rchild, key);
  
  else {
    tree_node* ptr = NULL;
    
    //if one child or no child
    if(!tree->Lchild) {
      ptr = tree->Rchild;
      tree->Rchild = NULL;
      delete(tree);
      return ptr;
    }
    //if only one child
    else if (!tree->Rchild) {
      ptr = tree->Lchild;
      tree->Lchild = NULL;
      delete(tree);
      return ptr;
    }
    //if two child
    else {
      ptr = tree->Rchild;
      while(ptr->Lchild) {
        ptr = ptr->Lchild;
      }
      
      //copy the next node value to tree
      tree->data = ptr->data;
      tree->key = ptr->key;
      
      //make Rchild equal the tree->Rchild with deletion of ptr
      tree->Rchild = deleteNode(tree->Rchild, ptr->key);
    }
  }
  return tree;
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
