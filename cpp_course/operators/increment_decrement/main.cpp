/*
Increment operator ++
Decrement operator --

Increments or decrements its operand by 1
Can be used with int, float and pointers

Prefix ++num
Postfix num++

Don't overuse this operator!
Alert! Never use it for the same variable in the same statement!
*/


#include <iostream>

using namespace std;

int main() {

    // Example 1: Simple example
    int counter {10};
    int result {0};

    cout << "Counter: " << counter << endl; // 10

    counter = counter + 1;
    cout << "Counter: " << counter << endl; // 11

    counter++;
    cout << "Counter: " << counter << endl; // 12

    ++counter;
    cout << "Counter: " << counter << endl; // 13

    // Example 2: pre-increment
    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl; // 10

    result = ++counter; // Note the pre-increment: first counter + 1, then result is assigned
    cout << "Counter: " << counter << endl; // 11
    cout << "Result: " << result << endl; // 11

    // Example 3: post-increment
    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl; // 10

    result = counter++; // Note the post-increment: first result = counter = 10, then counter + 1
    cout << "Counter: " << counter << endl; // 11
    cout << "Result: " << result << endl; // 10

    return 0;
}