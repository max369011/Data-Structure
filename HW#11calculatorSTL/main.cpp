#include <fstream>
#include <string>
#include "calc.h"

int main() {
    string str;

    //cout << "input your expression:";
    getline(cin, str);  // reading one line from keyboard

    Calculator calc(str);

    cout << calc.evaluate() << endl;

    return 0;
}