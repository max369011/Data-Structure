#include <string.h>
#include "calc.h"
#include <stack>
using namespace std;

int Calculator::priority(char op) {
    if (op == '*' || op == '/')
        return 3;
    else if (op == '+' || op == '-')
        return 2;
    else
        return 1;
}

string Calculator::infix2postfix() {
    int count = 0;
    int i;
    string post;
    stack <char> stack;

    //loop until end of string 
    while (infix[count] != '\0') {
        count++;
        continue;
    }
    
    //insert value inside stack
    stack.push('#');

    for (i = 0; i < count; i++) {
        if (infix[i] == ' ' )
            continue;

        //if operand loop until not a number or '.'
        else if (isdigit(infix[i]) || infix[i] == '.') {
            while (isdigit(infix[i]) || infix[i] == '.') {
                    post += infix[i++];
            }
            post += ' ';
            infix[i--];
        }

        else if (infix[i] == '(') {
            stack.push(infix[i]);
        }
        else if (infix[i] == ')') {
            //pop stack until stack top is '('
            while (stack.top() != '(') {
                post += stack.top();
                post += ' ';
                stack.pop();
            }
            stack.pop();  //removes '(' left in stack
        }
        else {
            //if operator
            if (priority(infix[i]) >= priority(stack.top())) {
                stack.push(infix[i]);
            }
            else {
                while (priority(infix[i]) <= priority(stack.top())) {
                    post += stack.top();
                    stack.pop();
                    post += ' ';
                }
            }
        }
    }
    
    //pop remaining operators inside stack
    while (!stack.empty()) {
        if(stack.top() != '#')
        post += stack.top();
        stack.pop();
        post += ' ';
    }
    return post;
}


float Calculator::evaluate(string str) {
    infix = str;
    postfix = infix2postfix();
    return evaluate();
}

float Calculator::evaluate() {
  stack <float> stack;
  char* token;
  float operand1, operand2;
  float val = 0;

  if(postfix.length() <= 0)
    return val;
    
  //divide string by " "
  token = strtok(&postfix[0], " ");
  while(token) {
    //if operand
    if(isdigit(token[0]) || token[0] == '.')
      stack.push(atof(token));
    else {
      //if operator
      operand1 = stack.top();
      stack.pop();
      operand2 = stack.top();
      stack.pop();

      if(token[0] == '+') val = operand2+operand1;
      else if(token[0] == '-') val = operand2-operand1;
      else if(token[0] == '*') val= operand2*operand1;
      else if(token[0] == '/') val= operand2/operand1;

      stack.push(val);
    }
    token = strtok(NULL, " ");
  }
  val = stack.top();

  //round float value to the nearest tenth
  float value = (int)(val * 10 + .5); 
  return (float)value / 10; 
}
