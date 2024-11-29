/******************************
 * Logical Operators:
 * not (!) - negation;
 * and (&&) - logical and;
 * or (||) - logical or;
 * 
 * Precedence:
 * "not" is higher than "and"
 * "and" is higher than "or"
 * 
 ******************************/
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    cout << boolalpha;
    uint16_t low_bound {10};
    uint16_t high_bound {20};

    uint16_t user_input {0};

    cout << "Enter the number: ";
    cin >> user_input;

    bool is_in_bounds = low_bound <= user_input && high_bound >= user_input;
    cout << "Is user input number between " << low_bound << " and " << high_bound << "?: " << is_in_bounds << endl;

    return 0;
}