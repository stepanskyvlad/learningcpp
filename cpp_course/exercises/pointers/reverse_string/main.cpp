#include <iostream>
#include <string>

std::string reverse_string(const std::string& str) {
    std::string reversed;

    const char* start = str.c_str();                    // Pointer to the first character
    const char* end = str.c_str() + str.size() - 1;     // Pointer to the last character

    while (end >= start) {
        reversed.push_back(*end);   // Append the character at the end pointer to the reversed string
        end--;
    }

    return reversed;
}

// std::string reverse_string(const std::string& str) {
    // Step 1: Create a new string to store the reversed result
    // std::string reversed(str.size(), '\0'); // Initialize a string of the same size filled with null characters

    // Step 2: Initialize two pointers
    // const char* read_ptr = str.c_str();          // Pointer to the first character of the input string
    // char* write_ptr = &reversed[reversed.size() - 1]; // Pointer to the last character of the reversed string

    // Step 3: Reverse the string using the two pointers
    // while (*read_ptr != '\0') { // Iterate until the null terminator is encountered
        // *write_ptr = *read_ptr; // Copy the character from input to the reversed string
        // ++read_ptr;             // Move the read pointer to the next character
        // --write_ptr;            // Move the write pointer backward in the reversed string
    // }

    // Step 4: Return the reversed string
    // return reversed;
// }

int main () {

    std::string input = "Hello, World!";
    std::string reversed = reverse_string(input);
    std::cout << reversed << std::endl;
    
    return 0;
}