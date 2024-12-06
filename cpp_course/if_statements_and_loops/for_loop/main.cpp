#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main() {

    // for (uint16_t i{1}; i <= 10; i++)
    //     cout << i << endl;

    // for (int i {10}; i > 0; --i)
    //     cout << i << endl;

    for (uint16_t i{10}; i<=100; i+=10) {
        // first the body executes (in this case - if statement), then - i+=10
        if (i % 15 == 0) {
            cout << i << endl;
        }
    }
    cout << "========================" << endl;

    for (uint16_t i {1}, j {5}; i <=5; ++i, ++j)
        cout << i << " + " << j << " = " << (i+j) << endl;

    cout << "========================" << endl;

    vector<int16_t> nums {10, 20, 30, 40, 50};
    for (uint16_t i {0}; i<nums.size(); ++i)
        cout << nums[i] << endl;

    return 0;
}