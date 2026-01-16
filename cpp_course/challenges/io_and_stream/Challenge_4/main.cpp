// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdint>

int main() {

    std::ifstream in_file {"romeoandjuliet"};
    if (!in_file) {
        std::cerr << "Cannot read the file." << std::endl;
        return 1;
    }

    std::ofstream out_file {"romeoandjuliet.txt"};
    if (!out_file) {
        std::cerr << "Cannot write in the file" << std::endl;
        return 1;
    }

    std::string poem_line {};
    uint16_t line_number {0};
    while (std::getline(in_file, poem_line)) {
        if (poem_line.find_first_not_of(" \t\r") == std::string::npos) {
            out_file << std::endl;
        } else {
            ++line_number;
            out_file << std::setw(7) << std::left << line_number << poem_line << std::endl;
        }
    }
    std::cout << "The file is copied" << std::endl;
    return 0;
}

