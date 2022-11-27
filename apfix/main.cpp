//
//  main.cpp
//  final-project
//
//  Created by Amor Wang & MW Giannini on 11/11/22.
//

#include <iostream>
#include <algorithm>
#include "helper.hpp"

int main(int argc, char** argv) {
    char* argument;
    char* postfix;
    double result;
    
    try {
        // Parse argument
        if(argc != 2) {
            throw "Invalid arguments!";
        }
        argument = argv[1];
        if(isHelpFlag(argument)) {
            std::cout << "Assembly Postfix Evaluator\n"
            << "usage: apfix <expression>" << std::endl;
        }
        
        // Infix to Postfix
        postfix = infixToPostfix(argument);
        
        // Evaluate the expression
        result = evalPostfix(postfix);
        cout << result;
    }
    catch ( const char* e ) {
        std::cout << e << '\n'
        << "try: apfix -h" << std::endl;
    }
    
    return 0;
}
