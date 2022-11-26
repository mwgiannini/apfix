//
//  helper.cpp
//  apfix
//
//  Created by Amor Wang & MW Giannini on 11/26/22.
//

#include "helper.hpp"
#include <string>

extern "C" double getValue(const char* input) {
    return std::stod(input);
}

bool isHelpFlag(char* argument) {
    return true;
}
bool isValidExpression(char* argument) {
    return true;
}
