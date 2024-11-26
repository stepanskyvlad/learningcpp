#include <iostream>
#include <cstdint>

using namespace std;


int main() {
    /************************
     * Character type
     ************************/
    char middle_initial {'J'}; // For char we use single quotes
    cout << "My middle initial is " << middle_initial << endl;

    /*************************
     * Integer types
     *************************/

    int8_t exam_score_1 {55}; // short
    cout << "Exam score is " << exam_score_1 << "(incorect print)" << endl;  // prints: Exam score 7
    /*
        Why 7?
        int8_t is often treated as a char type:
        On most systems, int8_t is a typedef for signed char. When you use std::cout to print it directly, std::cout interprets it as a character rather than a number.
        ASCII character codes are used in the output, so the value 55 corresponds to the ASCII character 7 (as '7' has an ASCII code of 55).
     */

    int8_t exam_score_2 {55}; // short -> 256
    std::cout << "Exam score is " << static_cast<int>(exam_score_2) << std::endl;

    int16_t cities {2650}; // int -> 65 536
    cout << "There were " << cities << " countries represented" << endl;

    int32_t people_in_florida {2000000}; // long -> 4 294 967 296
    cout << "There are " << people_in_florida << " people on Florida." << endl;

    int64_t people_on_earth {8'200'000'000}; // long long -> 18 446 744 073 709 551 615
    cout << "There are " << people_on_earth << " people on Earth." << endl;

    /******************************************
     * Floating point types
     ******************************************/
    float car_payment {401.23}; // 1.2 x 10^-38 to 3.4 x 10^38
    cout << "My car payment is " << car_payment << endl;

    double pi {3.14159};
    cout << "Pi is " << pi <<endl; // 2.2 x 10^-308 to 1.8 x 10^308

    long double large_amount {2.7e120};
    cout << large_amount << " is a very big number." << endl; // 3.3 x 10^-4932 to 1.2 x 10^4932

    /******************************************
     * Boolean type
     ******************************************/
    bool game_over {false};
    cout << "The value of gameOver is " << game_over << endl;

    /******************************************
     * Overflow example
     ******************************************/
    // short value1 {1280};
    // short value2 {1280};
    // short product {value1 *value2};
    // cout << "The sum of " << value1 << " and " << value2 << " is " << product << endl;

    /*******************************************
     * Size of in bytes
    ********************************************/
    cout << "large_amount is " << sizeof(large_amount) << " bytes." << endl;
    //or
    cout << "people_on_earth is " << sizeof people_on_earth << " bytes." << endl;

    return 0;
}
