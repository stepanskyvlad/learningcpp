// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <cctype>

void to_lowercase_string(std::string& s) {
    for (char& c: s) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
}

int main() {
    std::ifstream file;
    int word_counter = 0;
    std::string user_word;
    int match_counter = 0;
    std::cout << "Enter the substring to search for: ";
    std::cin >> user_word;
    to_lowercase_string(user_word);

    file.open("romeoandjuliet.txt");
    if (!file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::string word;
    while (file >> word) {
        word_counter++;
        std::string lowered = word;
        to_lowercase_string(lowered);
        if (lowered.find(user_word) != std::string::npos) {
            match_counter++;
        }
    }

    std::cout << word_counter << " words were searched..." << std::endl;
    std::cout << "The substring '" << user_word << "' was found " << match_counter << " times" << std::endl;

    return 0;
}
