/**
 * P - Print numbers
 * A - Add a number
 * M - Display mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * C - Clear the vector
 * F - Find number
 * Q - Quit
 * 
 * Enter your choice: A
 * Enter an integer to add to the list: 100
 * 100 added
 */
#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>  // accumulate
#include <algorithm> // min and max element from vector

using namespace std;

int main() {

    char user_choice;
    vector<int16_t> list_of_numbers;
    int16_t user_num;
    while (true) {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "C - Clear the vector" << endl;
        cout << "F - Find the number" << endl;
        cout << "Q - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;

        if (user_choice == 'q' || user_choice == 'Q') {
            break;

        } else if (user_choice == 'p' || user_choice == 'P') {
            if (list_of_numbers.empty()) {
                cout << "\n[] - the list is empty.\n" << endl;
            } else {
                cout << "\n[";
                for (int16_t number: list_of_numbers) {
                    cout << " " << number << " ";
                }
                cout << "]\n" << endl;
            }

        } else if (user_choice == 'a' || user_choice == 'A') {
            cout << "Enter an integer to add to the list: ";
            cin >> user_num;
            cout << user_num << " added!\n" << endl;
            list_of_numbers.push_back(user_num);

        } else if (user_choice == 'm' || user_choice == 'M') {
            if (list_of_numbers.empty()) {
                cout << "\nUnable to calculate mean - list is empty.\n" << endl;
            } else {
                double average = static_cast<double>(accumulate(list_of_numbers.begin(), list_of_numbers.end(), 0)) / list_of_numbers.size();
                cout << "\nThe mean of the numbers is: " << average << "\n" << endl;
            }

        } else if (user_choice == 's' || user_choice == 'S') {
            if (list_of_numbers.empty()) {
                cout << "\nUnable to determine the smallest number - list is empty.\n" << endl;
            } else {
                int16_t min {*min_element(list_of_numbers.begin(), list_of_numbers.end())};
                cout << "\nThe smallest numbers is: " << min << "\n" << endl;
            }

        } else if (user_choice == 'l' || user_choice == 'L') {
            if (list_of_numbers.empty()) {
                cout << "\nUnable to determine the largest number - list is empty.\n" << endl;
            } else {
                int16_t max {*max_element(list_of_numbers.begin(), list_of_numbers.end())};
                cout << "\nThe largest numbers is: " << max << "\n" << endl;
            }

        } else if (user_choice == 'c' || user_choice == 'C') {
            cout << "\nThe list is cleared!\n" << endl;
            list_of_numbers.clear();

        } else if (user_choice == 'f' || user_choice == 'f') {
            uint16_t counter {0};
            cout << "Enter an integer to add to the list: ";
            cin >> user_num;
            for (int16_t number: list_of_numbers) {
                if (number == user_num) {
                    counter += 1;
                }
            }
            if (counter <= 0) {
                cout << "There is no number " << user_num << " in the list\n" << endl;
            } else {
                cout << user_num << " occurs " << counter << " times\n" << endl;
            }

        } else {
            cout << "Wrong choice! Enter again!\n" << endl;
        } 

    }

    return 0;
}