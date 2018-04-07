#include "StackArr.h"
#include <iostream>
// check bracket status, balanced or not 
using namespace std;

bool bracket_check(string exp) {
    Stack <char> s;
    bool status = true;
    for(unsigned int i = 0; i < exp.length(); i++) {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            char temp;
            s.pop(temp);
            switch(exp[i]) {
                case ')':
                    if(temp == '[' || temp == '{') {
                        cout << "Invalid Expression\n";
                        return status = false;
                    }
                    break;
                case ']':
                    if(temp == '(' || temp == '{') {
                        cout << "Invalid Expression\n";
                        return status = false;                        
                    }
                    break;
                case '}':
                    if(temp == '[' || temp == '(') {
                        cout << "Invalid Expression\n";
                        return status = false;                        
                    }
                    break;
            }
        }
        else {
            cout << "Invalid Type\n";
            return status = false;
        }
    }
    if(!s.isEmpty()) {
        cout << "Expression is Invalid\n";
        return status = false;
    }
    return status;
}

int main(void) {
    string expression = "(){{[]}";
    bool stat = bracket_check(expression);
    cout << "Is expression" << expression << "balanced ?: " << stat << endl;
    return 0;
}
