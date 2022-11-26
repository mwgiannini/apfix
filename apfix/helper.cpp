//
//  helper.cpp
//  apfix
//
//  Created by Amor Wang & MW Giannini on 11/26/22.
//

#include "helper.hpp"

bool isHelpFlag(char* argument) {
    return true;
}
bool isValidExpression(char* argument) {
    return true;
}

string infixToPostfix(char* argument) {
    string result = argument;
    while(*argument != '\0'){
        cout << argument << endl;
        argument ++;
    }
    return result;
}
