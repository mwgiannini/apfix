//
//  stub.cpp
//  apfix
//
//  Created by MW Giannini on 11/26/22.
//

#include <iostream>
#include <assert.h>
#include "helper.hpp"

using namespace std;

int main() {
//    // Test getValue
//    {
//        string input = "3.14159";
//        double output = getValue(input.c_str());
//        
//        assert(output == 3.14159);
//    }
    
    // Test infixToPostfix
    {
        string input = " ( ( 1.5 * ( ( ( ( 33 + ( ( 2.645324 +234 ) * 422 ) ) * 0 ) * 342 ) * 4 ) ) + 0.4231 )";
        string output = infixToPostfix(input.c_str());
        
        assert(output == "1.5,33,2.645324,234,+,422,*,+,0,*,342,*,4,*,*,0.4231,+");
    }
    
    return 0;
}
