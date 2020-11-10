#include <string.h>
#include "calc.h"
#include "stack.h"

int Calculator::priority (char op) {
if(op =='*' || op == '/') 
  return 2;
else if(op == '+' || op=='-')
  return 1;
else 
  return -1;
}

string Calculator::infix2postfix() {
  Stack<char> operator_stack;
  string output ="";
  char newStr[1024];
  char trimStr[1024];
  strcpy(trimStr, infix.c_str());
  int count =0;
  
  //divide the string input to operators and operands with spaces in between 
  for(int i=0; i<infix.length() ; i++) {
    if(trimStr[i] == '(' ||trimStr[i] == ')'||trimStr[i] == '/'||trimStr[i] == '*'||trimStr[i] == '-'||trimStr[i] == '+') {
      if(i == infix.length()-1) {
        newStr[count++] = ' ';
        newStr[count++] = trimStr[i];
        newStr[count] = '\0';
        break;
      }
      newStr[count++] = ' ';
      newStr[count++] = trimStr[i];
      newStr[count++] = ' ';
      
    } else if((trimStr[i]>='0' && trimStr[i]<='9') || trimStr[i]=='.') { 
     if(i == infix.length()-1) {
        newStr[count++] = trimStr[i];
        newStr[count] = '\0';
        break;
      }
     newStr[count++] = trimStr[i];
    }
  }

  //cout<<newStr<<endl;
  char* ptr = strtok(newStr, " ");
  
  while(ptr!= NULL) {
    char c_ptr = *ptr;
    //cout<< c_ptr << endl;  
    //if operator
    if(c_ptr == '*'||c_ptr=='+'||c_ptr=='-'||c_ptr=='/') {

     if(priority(operator_stack.peek()) < priority(c_ptr)) {    //if priority inside the stack is lower than input char
          operator_stack.Push(c_ptr);
        } else if(priority(operator_stack.peek()) >= priority(c_ptr)) {   //if priority inside the stack is higher than input char
          while(priority(operator_stack.peek()) >= priority(c_ptr)) {     //pop until stack priority is lower
            char op = operator_stack.Pop();
            output = output + op + " ";
          }
          operator_stack.Push(c_ptr);
        }
     } else if (c_ptr == '(') {
        operator_stack.Push(c_ptr);
     } else if (c_ptr == ')') {
        while(operator_stack.peek() != '(') {
          char op = operator_stack.Pop();
          if(op != '(') 
          output = output + op + " ";
        }
        operator_stack.Pop();    //removes '(' inside the stack
    } 
    else {
      //if operand
      output = output + ptr + " ";
    }
  
  ptr = strtok(NULL, " ");
}
   while(operator_stack.peek() != '\0') {     //pop remaining char in stack
          char op = operator_stack.Pop();
          if(op != '(') 
          output = output + op + " ";
        }
  //cout<<"Infix to postfix: "<< output<< endl;
  return output;
}


float Calculator::evaluate(string str) {
    infix = str;
    postfix = infix2postfix();
    return evaluate();
}


float Calculator::evaluate() {
  Stack<float> stack;
  float op1, op2, newNum = 0;
  char trimStr[1024];
  strcpy(trimStr, postfix.c_str());

  char* ptr = strtok(trimStr, " ");
  while(ptr != NULL) {
    //cout<< ptr << endl;
    //if operator
    if(*ptr == '/' || *ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '\0' || *ptr == ' ') {
    char numCase = *ptr;
    op2 = stack. Pop();
    op1 = stack . Pop();
    
    switch(numCase) {
      case '+': 
      newNum = op1 + op2;
      stack.Push(newNum);
      break;
      case '-':
      newNum = op1 - op2;
      stack.Push(newNum);
      break;
      case '/':
      newNum = op1 / op2;
      stack.Push(newNum);
      break;
      case '*': 
      newNum = op1 * op2;
      stack.Push(newNum);
      break;
      case '\0':
      newNum = stack.Pop();
      cout << newNum << endl;
      break;
    }

    } else {
      //if operand
      float num = atof(ptr);
      stack.Push(num);
      }
    ptr = strtok(NULL, " ");
  } 

  float value = (int)(newNum * 10 + .5); 
  return (float)value / 10; 
}