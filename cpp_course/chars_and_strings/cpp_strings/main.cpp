#include <iostream>
#include <iomanip>
#include <string>

int main() {

    std::string s0;
    std::string s1 {"Apple"};
    std::string s2 {"Banana"};
    std::string s3 {"Kiwi"};
    std::string s4 {"apple"};
    std::string s5 {s1};  // Apple
    std::string s6 {s1, 0, 3};  //App - 3 is the length of substring from the index 0 
    std::string s7 (10, 'X');  //XXXXXXXXXX

    std::cout << s0 << std::endl;  // No garbage
    std::cout << s0.length() << std::endl;  // 0

    // Assignment
    std::cout << "===============Assignment==================" << std::endl;
    std::cout << s1 << std::endl;  // Apple
    s1 = "Watermelon";
    std::cout << s1 << std::endl;  // Watermelon

    std::cout << s2 << std::endl;  // Banana
    s2 = s1;
    std::cout << s2 << std::endl;  // Watermelon

    s3 = "Frank";
    s3[0] = 'C';  // Crank
    s3.at(0) = 'P';  // Prank

    // Concatenation
    std::cout << "===============Concatenation==================" << std::endl;
    s3 = "Watermelon";
    s2 = "Banana";

    s3 = s5 + " and " + s2 + " juice";  // Apple and Banana juice
    std::cout << "S3 is now: " << s3 << std::endl;  // S3 is now: Apple and Banana juice

    // s3 = "nice " + " cold " + s5;  // Compiler error, we cannot concatenate C-strings with each other

    // For loop
    std::cout << "===============For loop==================" << std::endl;
    s1 = "Apple";
    for (size_t i {0}; i < s1.length(); ++i)
        std::cout << s1.at(i);  // or s1[i]  Apple
    std::cout << std::endl;

    // Range-based for loop
    std::cout << "===============Range-based for loop==================" << std::endl;
    for (char c: s1)
        std::cout << c; // Apple
    std::cout << std::endl;

    // Substring
    std::cout << "===============Substring==================" << std::endl;
    s1 = "This is a test";

    std::cout << s1.substr(0, 4) << std::endl;  // start from index [0] and take [4] chars -> This
    std::cout << s1.substr(5, 2) << std::endl;  // is
    std::cout << s1.substr(10, 4) << std::endl;  // test

    // Erase
    std::cout << "===============Erase==================" << std::endl;
    s1 = "This is a test";
    s1.erase(0, 5);  // start from index 0  and remove 5 chars
    std::cout << s1 << std::endl;  // is a test

    // getline
    std::cout << "===============getline==================" << std::endl;
    // std::cin stops when see space " ".
    // getline take entire line, e.g. "Frank Johnson"

    std::string full_name {};
    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);
    std::cout << full_name << std::endl;

    // Find
    std::cout << "===============Find==================" << std::endl;
    s1 = "This is a test";

    std::string str_to_find {"test"};
    size_t position = s1.find(str_to_find);  // word starts from index 10
    if (position != std::string::npos)  // npos means that there isn't such index in string
        std::cout << "Found " << str_to_find << " at position: " << position << std::endl;
    else
        std::cout << "Sorry, " << str_to_find << " not found" << std::endl;

    return 0;
}