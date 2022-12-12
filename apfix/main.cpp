//
//  main.cpp
//  final-project
//
//  Created by Amor Wang & MW Giannini on 11/11/22.
//

#include "header.hpp"
using namespace std;

int main(int argc, char** argv) {
    const char* argument = argv[1];
    char* postfix = static_cast<char*>(malloc(1000));
    double result;
    try {
        if(argc != 2) {
            throw "Invalid arguments!\ntry: apfix -h";
        }
        if(isHelpFlag(argument)) {
            throw "Assembly Postfix Evaluator\nusage: apfix <expression>";
        }
        if(!isValidInfix(argument))
            throw "Invalid expression!";
        infixToPostfix(postfix, argument);
        result = evalPostfix(postfix);
        cout << result << endl;
    }
    catch ( const char* e ) {
        std::cout << e << std::endl;
    }
    free(postfix);
    return 0;
}
