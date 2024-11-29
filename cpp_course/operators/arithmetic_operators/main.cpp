#include <iostream>
#include <cstdint>

using namespace std;

int main() {

    uint16_t num1 {300};
    uint16_t num2 {100};
    uint16_t result {0};
    
    result = num1 / num2;
    cout << "Result is: " << result << endl; // 3

    result = num2 / num1;
    cout << "Result is: " << result << endl; // 0, because result is int

    // modulo operator is only used with integers
    result = num1 % num2;
    cout << "Result is: " << result << endl; // 300 / 100 = 3 -> reminder is 0

    result = num2 % num1;
    cout << "Result is: " << result << endl; // 100 / 300 = 0 -> reminder is 100

    num1 = 10;
    num2 = 3;
    result = num1 % num2;
    cout << "Result is: " << result << endl; // 10 / 3 = 3 -> reminder is 1

    float result_float;

    num1 = 300;
    num2 = 100;
    result_float = num2 / num1;
    cout << "Result_float is: " << result_float << endl; // 0 because num1 and num2 are ints


    float num3 = 300;
    float num4 = 100;
    result_float = num4 / num3;
    cout << "Result_float is: " << result_float << endl; // 0.333333 because num1 and num2 are floats





    return 0;
}