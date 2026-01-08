#include <iostream>
#include <string>

int main() {

    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string user_str;
    std::string encrypted_str;
    std::string decrypted_str;

    std::cout << "Enter your string: ";
    std::getline(std::cin, user_str);

    for (char letter: user_str) {
        size_t alphabet_indx = alphabet.find(letter);
        if (alphabet_indx != std::string::npos) {
            char encrypted_letter = key.at(alphabet_indx);
            encrypted_str += encrypted_letter;
        } else {
            encrypted_str += letter;
        }
    }

    std::cout << encrypted_str << std::endl;

    return 0;
}