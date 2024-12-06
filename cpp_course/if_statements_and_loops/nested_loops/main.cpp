#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    
    for (uint16_t num1 {1}; num1 < 10; ++num1) {
        for (uint16_t num2 {1}; num2 <= 10; ++num2) {
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        }
        cout << "--------------" << endl;
    }

    cout << "====================My solution================" << endl;
    /**
     * Another example:
     * Given the vector vec  to be {2, 4, 6, 8} , the possible pairs are (2,4), (2,6), (2,8), (4,6), (4,8), and (6,8).
     * So the result would be (2*4) + (2*6) + (2*8) + (4*6) + (4*8) + (6*8) which is 140.
     */
    vector<uint16_t> vec {1, 2, 3};
    uint16_t result {0};
    uint16_t shift {0};

    if (!(vec.empty() || vec.size() <= 1)) {
        for (uint16_t num: vec) {
            uint16_t indx {1};
            indx += shift;
            while (indx < vec.size()) {
                result += (num * vec.at(indx));
                indx += 1;
            }
            shift +=1; 
        }
    }
    cout << result << endl;

    cout << "===================Tutor solution==============" << endl;

    int result_1{};
    
    for (size_t i=0; i< vec.size(); ++i)
       for (size_t j=i+1; j< vec.size(); ++j) 
            result_1 = result_1 + vec.at(i) * vec.at(j);
    cout << result << endl;
    cout << endl;
    return 0;
}