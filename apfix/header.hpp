//
//  helper.hpp
//  apfix
//
//  Created by Amor Wang & MW Giannini on 11/26/22.
//

#ifndef helper_hpp
#define helper_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;

extern "C" void infixToPostfix(char* output, const char* input);
extern "C" double evalPostfix(const char* input);
extern "C" double getValue(const char* input);
extern "C" double getPower(double a, double b);
bool isHelpFlag(const char* argument);
bool isValidInfix(const char* input);

#endif /* helper_hpp */
