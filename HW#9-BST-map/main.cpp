#include <iostream>
#include <fstream>
#include <string.h>
#include "BST.h"
#define MAX 1024
using namespace std;

char *removeSpaces(char *str);

int main() {
  ifstream ifs1, ifs2, ifs3;
  BST* tree = new BST();
  string txtFile, mapFile;
  string key, value;
  int count = 0;
  int i =0;
  int lineCount[MAX];
  char* ptr;
  char line[MAX];
  
  cin >> txtFile;
  cin >> mapFile;
  
  ifs1.open(txtFile);
  ifs2.open(mapFile);
  ifs3.open(txtFile);
  
  if(ifs1.is_open() && ifs2.is_open()) {
    //Read and create map from map file using BST
    while(ifs2.getline(line,MAX)) {
      ptr = strtok(line,":");
      
        while(ptr!=NULL) 
        {
          switch(count) 
          {
            case 0:
              key = ptr;
              break;
            case 1: 
              value = removeSpaces(ptr);
              break;
          }
          count++;
          ptr = strtok(NULL, ":");
        }
          count = 0;
          tree->add(key, value);
   } 
  } else {
    cout << "Could not open file";
    exit(1);
  }
    
    
  //read text file
   while(ifs3.getline(line,MAX)) {
      ptr = strtok(line," ");
      //store number of words per line in file  
      while(ptr!=NULL) {
        count++;
        ptr=strtok(NULL," ");
      }
      lineCount[i++] = count;
      count=0;
    }
    
      
    i = 0;
    //Read and swap from txt file 
    while(ifs1.getline(line,MAX)) {
      ptr = strtok(line," ");
      
      while(ptr!=NULL) {
        if(tree->searchKey(ptr)) {
          count++;
          string newValue = tree->search(ptr);
          //if last word in the line
          if(count == lineCount[i]) {
            cout << newValue;
            i++;
          } else
            cout<< newValue << " ";
        } else {
           count++;
           //if last word in the line
           if(count == lineCount[i]) {
            cout<<ptr;
            i++;
           } else 
            cout<<ptr<<" ";
        }
        ptr=strtok(NULL," ");
      }
      count=0;
      cout<<endl;
    }
  
  ifs1.close();
  ifs2.close();
  ifs3.close();
  delete(tree);
}



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