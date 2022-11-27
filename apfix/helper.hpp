//
//  helper.hpp
//  apfix
//
//  Created by MW Giannini on 11/26/22.
//

#ifndef helper_hpp
#define helper_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <assert.h>
using namespace std;

extern "C" double evalPostfix(int length, const char* input);
extern "C" double getValue(const char* input);

bool isHelpFlag(char* argument);
bool isValidExpression(char* argument);
bool isOperator(const char & op);
int priority(const char & op);
string infixToPostfix(const char* argument);
#endif /* helper_hpp */
