/************************
 * 
 * (cond_expr) ? expr1 : expr2
 * 
 * cond_expr evaluates to a boolean expression
 * 
 * If cond_expr is true then the value of expr1 is returned
 * If cond_expr is false then the value of expr2 is returned
 ************************/
#include <iostream>
#include <cstdint>

using namespace std;

int main() {

    uint16_t num {};

    cout << "Enter an integer: ";
    cin >> num;

    cout << "==================If statement=============" << endl;
    if (num % 2 == 0)
        cout << num << " is even" << endl;
    else
        cout << num << " is odd" << endl;

    cout << "==================If statement=============" << endl;

    cout << num << " is " << ((num % 2 == 0) ? "even" : "odd") << endl;



    return 0;
}