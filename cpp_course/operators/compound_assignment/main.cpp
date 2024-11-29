/************************************
 * num1 += num2 ------> num1 = num1 + num2
 * -=
 * *=
 * /=
 * %=
 * >>=
 * <<=
 * &=
 * ^=
 * |=
 ************************************/
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    uint16_t a {10}, b {20}, c{30};

    a *= b + c; // a = a * (b + c)

    cout << a << endl; // 500

    return 0;
}