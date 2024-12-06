/*****************************************
 * continue:
 * no further statements in the body of the loop are executed.
 * control immediately goes directly to the beginning of the loop
 * 
 * break:
 * no further statements in the body of the loop are executed.
 * loop is immediately terminated.
 * control goes out of the loop.
 *****************************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> values {1, 2, -1, 3, -1, -99, 7, 8, 10};
    for (int val: values) {
        if (val == -99)
            break;
        else if (val == -1)
            continue;
        else
            cout << val << endl;
    }
    // 1, 2, 3 will be printed
    return 0; 
}