#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include <iostream>
#include "contact.h"

using namespace std;

void Contact :: load (string file_name) {
  char c_str[1024];
  char in_line[1024];
  fstream inFile;
  
  strcpy(c_str, file_name.c_str()); //copying string to c_str (char array)  cstr == filename
  inFile.open(c_str);

  while(inFile.getline(in_line, 1024)){
    persons[total_num] = str2person(in_line);
    //cout << "person[" << total_num << "]= " << in_line << endl;
    total_num++;
  }
}


Date Contact:: str2date(char* str){
  Date date;
  char temp [15];
  
  strncpy(temp, str, 5);
  temp[5] = 0;
  date.year = atoi(temp);
  
  strncpy(temp, str+5, 3);
  temp[3] = 0;
  date.month = atoi(temp);
  
  strncpy(temp, str+8, 3);
  temp[3] = 0;
  date.day = atoi(temp);
  return date;
}


char* Contact::trim(char* str) {
     char *token;
     
 token = strtok(str, ";"); 
 return token;
}


void Contact :: print() {
  //implement here
  Person* c ;
  for(int i=0 ;i<total_num; i++) {
    c = &persons[i];
  cout << c->name << "; " <<c->dob.year<< c->dob.month << c->dob.day << "; "  << c->email << "; "  << c->phone << endl; 
  }
}



//implement other functions here
Person Contact:: str2person(char* person_name) {
  Person persons;
  char* token;
  char temp[64];
  int count = 0;
  
  token = trim(person_name);
  while(token) {
  strcpy(temp, token);
  switch(count) {
    case 0: strcpy(persons.name, temp); break;
    case 1: persons.dob = str2date(temp); break;
    case 2: strcpy(persons.email, temp);  break;
    case 3: strcpy(persons.phone, temp); break;
  }
  count ++;
  token = strtok(NULL, ";");
  }
  return persons;
}

