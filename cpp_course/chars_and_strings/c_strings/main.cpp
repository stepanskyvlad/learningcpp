#include <iostream>
#include <cstring>  // for c-style string functions
#include <cctype>  // for character-based functions

using namespace std;

int main() 
{
    char first_name[20];
    char last_name[20];
    char full_name[50];

    // cout << first_name << endl;  // Will likely display garbage!

    cout << "Please enter you first name: ";
    cin >> first_name;
    cout << "Please enter you last name: ";
    cin >> last_name;
    cout << "================================" << endl;

    cout << first_name << " has " << strlen(first_name) << " chars" << endl;
    cout << last_name << " has " << strlen(last_name) << " chars" << endl;

    strcpy(full_name, first_name);  // copy first_name to full_name
    strcat(full_name, " "); // concatenate full_name and a space
    strcat(full_name, last_name); // concatenate last_name to full_name
    cout << "Your full name is " << full_name << endl;

    for (size_t i{0}; i < strlen(full_name); ++i) {  // len of str
        if (isalpha(full_name[i])) { // check if the char is a letter
            full_name[i] = toupper(full_name[i]); // make each letter in upper case
        }
    }
    cout << "Your full name is " << full_name << endl;



    return 0;
}