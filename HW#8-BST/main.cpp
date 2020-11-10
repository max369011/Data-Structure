#include <iostream>
#include <fstream>
#include <string.h>
#include "BST.h"
#define MAX 1024
using namespace std;

int main() {
  ifstream ifs;
  BST* tree = new BST();
  string fileName;
  char line[MAX];
  int key, count = 0;
  string value, command;
  
  cin >> fileName;
  
  ifs.open(fileName);

  if(ifs.is_open()) {
    
    while(ifs.getline(line,MAX)) 
    {
      char* ptr = strtok(line, " ");

      while(ptr!=NULL) 
      {
       //save inputs to the following variables using count
       switch(count) {
         case 0:
          command = ptr;
          break;
         case 1:
          key = atoi(ptr);
          break;
         case 2:
          value = ptr;
          break;
       }
       count++;
       ptr = strtok(NULL, " ");
      }
       count = 0;
      
    //run according to the command option
    if(command == "a") 
        tree->add(key, value);
    else if(command == "d") 
        tree->remove(key);
    else if (command == "p") 
        tree->print();
    else if (command =="q")         
        break;
    
   }
  } else {
    cout << "Could not open file";
    exit(1);
  }
  delete(tree);
}
