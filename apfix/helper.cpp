//
//  helper.cpp
//  apfix
//
//  Created by Amor Wang & MW Giannini on 11/26/22.
//

#include "helper.hpp"

extern "C" double getValue(char* input) {
    return 0;
}

bool isHelpFlag(char* argument) {
    return true;
}
bool isValidExpression(char* argument) {
    return true;
}

bool isOperator(const char & op) {
    if( op == '+' || op == '-' || op == '*' || op == '/') {
        return true;
    }
    else return false;
}

int priority(const char & op) {
    int priority = 1;
    if(op == '-' || op =='+')
            priority = 2;
    if(op == '*' || op =='/')
            priority = 3;
    return priority;
}


string infixToPostfix(const char* argument) {
    stack<char> operators;
    string postfix;
    int i = 0;
    char character = *argument;
    for (; character != '\0'; i ++) {
        character = argument[i];
        // If the character is a space or comma, then skip to next loop
        if (character != ' ' && character != ',') {
            if ((character >= '0' && character <= '9')|| character =='.') {
                postfix += character;
                if (argument[i+1] == ' ' && argument[i+1] == ',') {
                    postfix += ',';
                }
            }
            else if(character=='(') {
                operators.push(character);
            }
            else if(character==')') {
                while(operators.top()!='(') {
                    postfix += ',';
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
            else {
                postfix += ',';
                while (!operators.empty() && priority(character) <= priority(operators.top())){
                    postfix += operators.top();
                    operators.pop();
                    postfix += ',';
                }
                operators.push(character);
            }
        }
    }
    if (!operators.empty()) {
        throw "Invalid expression!";
    }

    return postfix;
}

