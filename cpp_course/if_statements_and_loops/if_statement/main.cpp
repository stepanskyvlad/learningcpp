#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int num {};
    const int min {10};
    const int max {100};

    cout << "Enter a number between " << min << " and " << max << ": ";
    cin >> num;

    if (num >= min) {
        cout << "\n====================If statement 1====================" << endl;
        cout << num << " is greater than " << min << endl;

        int diff {num - min}; // this variable is accessible in this if block
        cout << num << " is " << diff << " greater than " << min << endl;
    }

    if (num >= min && num <= max) {
        cout << "\n====================If statement 2====================" << endl;
        cout << num << " is in a range"<< endl;
    }


    cout << "\n====================If-else statement====================" << endl;
    uint16_t user_num {};
    const uint16_t target {10};

    cout << "Enter the number and compare it to " << target << ": ";
    cin >> user_num;

    if (user_num > target) {
        cout << "\n====================If block====================" << endl;
        cout << user_num << " is grater than " << target << endl;
    } else if (user_num < target) {
        cout << "\n====================if-else block====================" << endl;
        cout << user_num << " is less than " << target << endl;
    } else {
        cout << "\n====================else block====================" << endl;
        cout << user_num << " is equal to " << target << endl;
    }
    
    return 0;
}