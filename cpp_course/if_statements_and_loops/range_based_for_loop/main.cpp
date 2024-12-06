#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    uint16_t scores[] {10, 20, 30};

    for (uint16_t score: scores) {
        cout << score << endl;
    }

    cout << "=============" << endl;

    vector<double> temperatures {87.9, 77.9, 80.0, 72.5};
    double average_temp {};
    double total {};

    for (double temp: temperatures)
        total += temp;

    if (temperatures.size() != 0 )
        average_temp = total / temperatures.size();

    // round output: std library, include iomainip
    cout << fixed << setprecision(1);
    cout << "Average temperatures is " << average_temp << endl;

    cout << "=============" << endl;

    string user_str {"This is a test!"};

    for (char c: user_str) {
        if (c == ' ') {
            cout << "\t";
        } else {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}