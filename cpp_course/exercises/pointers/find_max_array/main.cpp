#include <iostream>
using namespace std;

// TODO: Define findMax(int *arr, int size) returning a pointer
int* findMax(int *arr, int size) {
    int *ptr = arr;  // ✅ Start with the first element

    for (int i = 1; i < size; i++) {  // ✅ Start from index 1
        if (*ptr < arr[i]) {
            ptr = &arr[i];  // Update max pointer
        }
    }
    return ptr;
}


int main() {
    int numbers[] = {20, 55, 89, 14, 77};  
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // TODO: Get pointer to max element
    int *maxElement = findMax(numbers, size);

    cout << "Largest element: " << *maxElement << endl;  // Dereference pointer
    return 0;
}
