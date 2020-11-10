#ifndef  __CALC_H__
#define  __CALC_H__

#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

class Calculator {
    private:
        string infix;
        string postfix;

        int priority (char);

    public:
        Calculator(string in_str) {
            infix = in_str;
            postfix = infix2postfix();
        };
        string infix2postfix();
        float evaluate();
        float evaluate(string);
        string get_postfix(){ return postfix;};
};

#endif