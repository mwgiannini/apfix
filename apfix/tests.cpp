//
//  stub.cpp
//  apfix
//
//  Created by Amor Wang & MW Giannini on 11/26/22.
//

#include "header.hpp"

int main() {
    const bool TEST_evalPostfix = true;
    const bool TEST_infixToPostfix = true;
    
    if(TEST_evalPostfix) {
        {
            std::string input = "0,2,-,3.3,3,/,5,2,^,+,0,4,2,^,-,1,*,-,+";
            double output = evalPostfix(input.c_str());
            
            assert(output == 40.1);
        }
        {
            std::string input = "4.125,5.5,-";
            double output = evalPostfix(input.c_str());

            assert(output == -1.375);
        }
        {
            std::string input = "1,3,+,5,20,*,-";
            double output = evalPostfix(input.c_str());

            assert(output == -96);
        }
        {
            std::string input = "100,43,-,5.7,/,10,/";
            double output = evalPostfix(input.c_str());

            assert(output == 1.0);
        }
        {
            std::string input = "1.5,33,2.0625,234,+,422,*,+,99,*,342,*,4,*,*,0.125,+";
            double output = evalPostfix(input.c_str());

            assert(output == 20243977528.625);
        }
    }
    
    if (TEST_infixToPostfix) {
        char* output = static_cast<char*>(malloc(1000));
        assert(output != NULL);
        {
            const char* input = "1+3-5*20";
            infixToPostfix(output, input);
            assert(std::string(output) == "1,3,+,5,20,*,-");
        }
        {
            const char* input = "-1+3";
            infixToPostfix(output, input);
            assert(std::string(output) == "0,1,-,3,+");
        }
        {
            const char* input = "(100-43)/5.7/10";
            infixToPostfix(output, input);
            assert(std::string(output) == "100,43,-,5.7,/,10,/");
        }
        {
            const char* input = "((1.5*((((33+((2.645324+234)*422))*99)*342)*4))+0.4231)";
            infixToPostfix(output, input);
            assert(std::string(output) == "1.5,33,2.645324,234,+,422,*,+,99,*,342,*,4,*,*,0.4231,+");
        }
        free(output);
    }
    return 0;
}
