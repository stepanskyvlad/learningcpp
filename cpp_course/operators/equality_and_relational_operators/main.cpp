#include <iostream>

using namespace std;

int main() {

    bool equal_result {false};
    bool not_equal_result {false};

    int num1{}, num2{};

    cout << boolalpha; // will display true/false instead of 1/0 for booleans. It doesn't print anything.

    num1 = 10;
    num2 = 20;

    equal_result = (num1 == num2); // false
    not_equal_result = (num1 != num2); // true

    cout << equal_result << endl;
    cout << not_equal_result << endl;

    cout << "**************************" << endl;

    /*********************************
     * float: ~7 decimal digits.
     * double: ~15–16 decimal digits.
     * 
     * Precision: A float has about 7 significant decimal digits because the mantissa only has 23 bits to store the number in binary.
     * Range: The exponent allows a float to represent numbers as small as 1.4×10^−45, 
     * but only with 7 significant decimal digits of precision.
     *********************************/

    double double1{}, double2{};
    double1 = 12.0;
    double2 = 11.9999999999999999; // 18 digits, 16 digits after float
    
    equal_result = (double1 == double2); // true, because of precision
    not_equal_result = (double1 != double2); // false

    cout << equal_result << endl;
    cout << not_equal_result << endl;

    cout << "**************************" << endl;   

    num1 = 10;
    double1 = 10.0;

    equal_result = (double1 == num1); // true
    not_equal_result = (double1 != num1); // false

    cout << equal_result << endl;
    cout << not_equal_result << endl;

    /**
     * There are other operators like:
     * > - greater than
     * >= - greater than or equal to
     * < - less than
     * <= - less than or equal to
     * 
     * They work pretty the same as in other programming languages.
     */

    return 0;
}