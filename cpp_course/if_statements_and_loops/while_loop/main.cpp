#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {

    uint16_t num {};


    cout << "Enter a positive integer to count up to: ";
    cin >> num;

    int i {1};
    while (num >= i) {
        cout << i << endl;
        i++;
    } 

    cout << "========================" << endl;

    cout << "Enter an integer less than 100: ";
    cin >> num;

    while (num >= 100) {
        cout << "Enter an integer less than 100: ";
        cin >> num;
    }
    cout << "Thanks!" << endl;

    cout << "========================" << endl;
    bool done {false};
    

    cout << "Enter an integer between 1 and 5: ";
    cin >> num;
    while (!done) {
        if (num <= 1 || num >=  5) {
            cout << "Enter an integer between 1 and 5: ";
            cin >> num;
        } else {
            cout << "Thanks!" << endl;
            done = true;
        }
    }
    
    /**
     * Given a vector of integers, determine how many integers are present before you see the value -99. 
     * Note, it's possible -99  is not in the vector! 
     * If -99  is not in the vector then the result will be equal to the number of elements in the vector. 
     * The final result should be stored in an integer variable named count .
     */
    cout << "========================" << endl;
    vector<int16_t> vec {10, 20, 30, -99, 40};
    uint16_t count {0};
    size_t index {0};

    while ( index < vec.size() && vec.at(index) != -99 ) {
        ++count;
        ++index;
    }
    cout << count << endl;

    return 0;
}