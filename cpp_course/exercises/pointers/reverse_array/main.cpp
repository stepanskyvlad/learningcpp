#include <iostream>

void reverse_array(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    // Tutor's solution
    // int *start = arr;
    // int *end = arr + size - 1;
    // while (start < end) {
    //     // swap elements pointed to by start and end pointers
    //     int temp = *start;
    //     *start = *end;
    //     *end = temp;
        
    //     // Move the pointers towards the center
    //     start++;
    //     end--;
    // }
}

int main () {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "\n[";
    for (int16_t number: arr) {
        std::cout << " " << number << " ";
    }
    std::cout << "]\n" << std::endl;
 
    reverse_array(arr, size);

    std::cout << "\n[";
    for (int16_t number: arr) {
        std::cout << " " << number << " ";
    }
    std::cout << "]\n" << std::endl;
    
    return 0;
}