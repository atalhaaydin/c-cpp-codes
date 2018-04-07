#include "StackArr.h"
#include <iostream>
// infix to postfix and single digit postfix calculator
using namespace std;

int prec(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infix_to_postfix(string infix) {
    string postfix = "";
    Stack <char> s;
    char temp, popped, check;
    
    for(unsigned int i = 0; i < infix.length(); i++) {
        if(infix[i] >= '0' && infix[i] <= '9') {
            postfix += infix[i];
        }
        if(infix[i] == '(') {
            s.push(infix[i]);
        }
        if(infix[i] == ')') {
            while(1) {
                s.peak(check);
                if(check == '(') {
                    s.pop(popped);
                    break;
                }
                s.pop(popped);
                postfix += popped;
            }
        }
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {
            s.peak(temp);
            while(!s.isEmpty() && prec(infix[i]) <= prec(temp)) {
                s.pop(popped);
                postfix += popped;
            }
            s.push(infix[i]);
        }
    }
    while(!s.isEmpty()) {
        s.pop(popped);
        postfix += popped;
    }
    return postfix;
}

int calculate_postfix(string postfix) { // for single digits
    char sym;
    int res, popped1, popped2;
    Stack<int> s;
    for(unsigned int i = 0; i < postfix.length(); i++) {
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            s.push(postfix[i] - '0');
        }
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            sym = postfix[i];
            s.pop(popped2);
            s.pop(popped1);
            switch(sym) {
                case '+':
                    res = popped1 + popped2;
                    break;
                case '-':
                    res = popped1 - popped2;
                    break;
                case '*':
                    res = popped1 * popped2;
                    break;
                case '/':
                    res = popped1 / popped2;
                    break;
            }
            s.push(res);
        }
    }
    s.pop(popped1);
    if(!s.isEmpty()) return -1;
    res = popped1;
    return res;
}

int main(void) {
    string expression = "(8+1)*2-2"; // 25
    string postfix_ = infix_to_postfix(expression);
    cout << "Postfix form of " << expression
        << " is: " << postfix_ << endl;
    string post = "35+";

    cout << post << " = " << calculate_postfix(post) << endl;    
    cout << postfix_ << " = " << calculate_postfix(postfix_) << endl;
    return 0;
}
