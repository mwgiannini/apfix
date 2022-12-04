//
//  helper.cpp
//  apfix
//
//  Created by Amor Wang & MW Giannini on 11/26/22.
//

#include "header.hpp"

extern "C" double getValue(const char* input) {
    std::string s(input);
    return std::stod(s);
}
extern "C" double getPower(double a, double b) {
    return std::pow(a, b);
}

bool isHelpFlag(char* argument) {
    return std::string(argument) == "-h";
}

bool isOperator(const char & op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}
