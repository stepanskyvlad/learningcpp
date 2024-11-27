#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    
    /* Initialization Example
    ELEMENT_TYPE array_name [number of elements] {init list}
    */

    uint16_t test_scores [5] {100, 95, 90, 85, 80};
    cout << "First element: " << test_scores[0] << endl;
    cout << "Fifth element: " << test_scores[4] << endl;
    // Be careful - there's no bounds checking
    // cout << "Sixth element: " << test_scores[5] << endl; --> throw a random number

    double hi_temps [] {90.1, 89.8, 77.5, 81.6};
    cout << "\nThe first high temperature is: " << hi_temps[0] << endl;

    hi_temps[0] = 100.7;

    cout << "\nThe first high temperature is now: " << hi_temps[0] << endl;

    uint16_t my_array [3] {100};
    cout << "Element 1: " << my_array[0] << endl; // 100
    cout << "Element 2: " << my_array[1] << endl; // 0
    cout << "Element 3: " << my_array[2] << endl; // 0

    // Initializing multi-dimensional arrays
    uint16_t movie_rating [3] [4] 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Element[1][3] is " << movie_rating[1][3] << endl;

    return 0;
}