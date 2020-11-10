#include <iostream>
#include <fstream>
#include <string.h>
#include "stack.h"
#define MAX_SIZE 1024
using namespace std;

char *removeSpaces(char *str);

int main() 
{ 
  ifstream ifs;
  string fileName;
  char line[MAX_SIZE];
  Stack_List* stack = new Stack_List;
  
  // Read from the input files
  cin >> fileName;
  
  ifs.open(fileName);
  
  //check whether file is opened
  if(ifs.is_open()) 
  {
    while(ifs.getline(line, MAX_SIZE))    
    {
      char*ptr = strtok(line, ",");
      
      //add strings name, id, email to stack until NULL
      while(ptr!= NULL) 
      {               
      stack->push(removeSpaces(ptr));
      ptr = strtok(NULL, ",");      
      }
    } 
  } else {
      cout << "Could not open file";
      exit(1);
    }

  //pop from stack until empty
  while(!stack->isEmpty()) 
  {
    string email = stack->pop();
    string age = stack->pop();
    string id = stack->pop();
    cout << age << ", " << id << ", " << email << endl;
  }
  
  ifs.close();
  delete (stack);
  return 0;
}


//Removes the spaces in called char array
char *removeSpaces(char *temp) 
{ 
    int i = 0, j = 0; 
    while (temp[i]) 
    { 
        if (temp[i] != ' ') 
           temp[j++] = temp[i]; 
        i++; 
    } 
    
    temp[j] = '\0'; 
    return temp; 
} 