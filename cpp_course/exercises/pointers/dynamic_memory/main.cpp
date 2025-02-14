#include <iostream>
#include <cstring>  // strcpy
using namespace std;

// TODO: Implement reverseString(char* str, int length)
void reverseString(char* str, int length) {
    char *left = str;
    char *right = str + length - 1;

    while (left < right) {
        swap(*left, *right);
        left++;
        right--;
    }
    
}

int main() {
    string input;
    cout << "Enter a word: ";
    cin >> input;

    int input_length = input.length();
    cout << "Input string length: " << input_length << endl;

    // TODO: Allocate a dynamic character array
    char *my_str_ptr = new char[input_length + 1];

    // TODO: Copy input string into dynamic array
    for (int i {0}; i < input_length; i++) {
        my_str_ptr[i] = input[i];
    }
    my_str_ptr[input_length] = '\0';  // to make array of chars a C-style string

    // OR
    // strcpy(my_str_ptr, input.c_str());

    // TODO: Call reverseString()
    reverseString(my_str_ptr, input_length);
    cout << "Reversed word: ";

    // TODO: Print the reversed word
    cout << my_str_ptr << endl;  // we can simply print such string.

    // TODO: Free the memory
    delete [] my_str_ptr;
    my_str_ptr = nullptr;

    return 0;
}
