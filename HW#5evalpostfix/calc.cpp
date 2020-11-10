#include <string.h>
#include "calc.h"
#include "stack.h"
using namespace std;

float Calculator::evaluate() {
  Stack* stack = new Stack();
  float op1, op2, newNum = 0;
  char trimStr[1024];
  strcpy(trimStr, postfix.c_str());

  char* ptr = strtok(trimStr, " ");
  while(ptr != NULL) {
    //cout<< ptr << endl;
    //if operator
    if(*ptr == '/' || *ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '\0' || *ptr == ' ') {
    char numCase = *ptr;
    op2 = stack-> Pop();
    op1 = stack -> Pop();
    
    switch(numCase) {
      case '+': 
      newNum = op1 + op2;
      stack -> Push(newNum);
      break;
      case '-':
      newNum = op1 - op2;
      stack -> Push(newNum);
      break;
      case '/':
      newNum = op1 / op2;
      stack -> Push(newNum);
      break;
      case '*': 
      newNum = op1 * op2;
      stack-> Push(newNum);
      break;
      case '\0':
      newNum = stack->Pop();
      cout << newNum << endl;
      break;
    }

    } else {
      //if operand
      float num = atof(ptr);
      stack->Push(num);
      }
    ptr = strtok(NULL, " ");
  } 
  
  return newNum;
}