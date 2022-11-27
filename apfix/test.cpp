//
//  stub.cpp
//  apfix
//
//  Created by MW Giannini on 11/26/22.
//

#include "helper.hpp"

using namespace std;

int main() {
    try {
        // Test evalPostfix
        //    {
        //        string input = "1,3,+,5,20,*,-,";
        //        int length = static_cast<int>(input.length());
        //        double output = evalPostfix(length, input.c_str());
        //
        //        assert(output == -96);
        //    }
        //    {
        //        string input = "100,43,-,5.7,/,10,/,";
        //        int length = static_cast<int>(input.length());
        //        double output = evalPostfix(length, input.c_str());
        //
        //        assert(output == 1.0);
        //    }
        //    {
        //        string input = "1.5,33,2.645324,234,+,422,*,+,99,*,342,*,4,*,*,0.4231,+,";
        //        int length = static_cast<int>(input.length());
        //        double output = evalPostfix(length, input.c_str());
        //
        //        assert(output == 20293914354.543);
        //    }
        //
        //     Test infixToPostfix
        {
            string input = "1 + 3 - 5 * 20";
            string output = infixToPostfix(input.c_str());
            
            assert(output == "1,3,+,5,20,*,-,");
        }
        {
            string input = "(100 - 43) / 5.7/10";
            string output = infixToPostfix(input.c_str());
            
            assert(output == "100,43,-,5.7,/,10,/,");
        }
        {
            string input = " ( ( 1.5 * ( ( ( ( 33 + ( ( 2.645324 +234 ) * 422 ) ) * 99 ) * 342 ) * 4 ) ) + 0.4231 )";
            string output = infixToPostfix(input.c_str());
            
            assert(output == "1.5,33,2.645324,234,+,422,*,+,99,*,342,*,4,*,*,0.4231,+,");
        }
        {
            string input = " 1+";
            string output = infixToPostfix(input.c_str());
            
        }
        {
            string input = " 42 2 -  1";
            string output = infixToPostfix(input.c_str());
        }
        {
            string input = " 412 31 3 - +-  1";
            string output = infixToPostfix(input.c_str());
        }

    }
    catch ( const char* e ) {
        cout << e << '\n';
    }
    return 0;
}
