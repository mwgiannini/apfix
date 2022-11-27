//
//  stub.cpp
//  apfix
//
//  Created by MW Giannini on 11/26/22.
//

#include <iostream>
#include <assert.h>
#include "helper.hpp"

int main() {
    // Test getValue
    {
        std::string input = "3.14159";
        double output = getValue(input.c_str());
        
        assert(output == 3.14159);
    }
    
    // evalPostfix testcase #1
    {
        std::string input = "4.125,5.5,-";
        int length = static_cast<int>(input.length());
        double output = evalPostfix(length, input.c_str());
        
        assert(output == -1.375);
    }
    
    // Test infixToPostfix
//    {
//        std::string input = "";
//        std::string output = infixToPostfix(input);
//
//        assert(output == "");
//    }
    
    return 0;
}
