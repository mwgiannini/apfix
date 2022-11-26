//
//  helper.hpp
//  apfix
//
//  Created by MW Giannini on 11/26/22.
//

#ifndef helper_hpp
#define helper_hpp

#include <string>

using namespace std;

bool isHelpFlag(char* argument);
bool isValidExpression(char* argument);
string infixToPostfix(char* argument);
#endif /* helper_hpp */
