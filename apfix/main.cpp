//
//  main.cpp
//  final-project
//
//  Created by Amor Wang & MW Giannini on 11/11/22.
//

#include "header.hpp"

int main(int argc, char** argv) {
    char* argument;
    string postfix;
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
        else{
            // Infix to Postfix
            postfix = infixToPostfix(argument);
            
            // Evaluate the expression
            result = evalPostfix(static_cast<int>(postfix.length()), postfix.c_str());
            cout << result << endl;
        }
    }
    catch ( const char* e ) {
        std::cout << e << '\n'
        << "try: apfix -h" << std::endl;
    }
    
    return 0;
}
