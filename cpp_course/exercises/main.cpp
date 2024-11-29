#include <iostream>
#include <cstdint>

using namespace std;

int main() {

    uint16_t cents {0}, dollars {0}, quarters {0}, dimes {0}, nickels {0}, pennies {0};
    cout << "Enter number of cents: ";
    cin >> cents;

    cout << "Change:" << endl;

    dollars = cents / 100;
    cents %= 100;
    cout << "dollars: " << dollars << endl;

    quarters = cents / 25;
    cents %= 25;
    cout << "quarters: " << quarters << endl;

    dimes = cents / 10;
    cents %= 10;
    cout << "dimes: " << dimes << endl;

    nickels = cents / 5;
    cents %= 5;
    cout << "nickels: " << nickels << endl;

    pennies = cents;
    cout << "pennies: " << pennies << endl;

    return 0;
}