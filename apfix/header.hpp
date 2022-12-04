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
#include <cmath>
#include <assert.h>

extern "C" const char* infixToPostfix(const char* input) {return 0;}
extern "C" double evalPostfix(const char* input);
extern "C" double getValue(const char* input);
extern "C" double getPower(double a, double b);
//bool isValidInfix(const char* input);

bool isHelpFlag(char* argument);
bool isOperator(const char & op);

#endif /* helper_hpp */
