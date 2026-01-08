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
#include <cctype> // toupper()

void show_menu();
char get_choice();
void handle_wrong_choice();
void handle_print(std::vector<int16_t> &list_of_numbers);
void handle_add(std::vector<int16_t> &list_of_numbers);
void handle_mean(std::vector<int16_t> &list_of_numbers);
void handle_small(std::vector<int16_t> &list_of_numbers);
void handle_large(std::vector<int16_t> &list_of_numbers);
void handle_clear(std::vector<int16_t> &list_of_numbers);
void handle_find(std::vector<int16_t> &list_of_numbers);


void show_menu()
{
    std::cout << "P - Print numbers" << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "C - Clear the vector" << std::endl;
    std::cout << "F - Find the number" << std::endl;
    std::cout << "Q - Quit" << std::endl;
    std::cout << std::endl;
}

char get_choice()
{
    char user_choice;
    std::cout << "Enter your choice: ";
    std::cin >> user_choice;
    return toupper(user_choice);
}

void handle_print(std::vector<int16_t> &list_of_numbers)
{
    if (list_of_numbers.empty()) {
        std::cout << "\n[] - the list is empty.\n" << std::endl;
    } else {
        std::cout << "\n[";
        for (int16_t number: list_of_numbers) {
            std::cout << " " << number << " ";
        }
        std::cout << "]\n" << std::endl;
    }
}

void handle_add(std::vector<int16_t> &list_of_numbers)
{
    uint16_t user_num;
    std::cout << "Enter an integer to add to the list: ";
    std::cin >> user_num;
    std::cout << user_num << " added!\n" << std::endl;
    list_of_numbers.push_back(user_num);
}

void handle_find(std::vector<int16_t> &list_of_numbers)
{
    uint16_t user_num;
    uint16_t counter {0};
    std::cout << "Enter an integer to add to the list: ";
    std::cin >> user_num;
    for (int16_t number: list_of_numbers) {
        if (number == user_num) {
            counter += 1;
        }
    }
    if (counter <= 0) {
        std::cout << "There is no number " << user_num << " in the list\n" << std::endl;
    } else {
        std::cout << user_num << " occurs " << counter << " times\n" << std::endl;
    }
}

void handle_mean(std::vector<int16_t> &list_of_numbers)
{
    if (list_of_numbers.empty()) {
        std::cout << "\nUnable to calculate mean - list is empty.\n" << std::endl;
    } else {
        double average = static_cast<double>(accumulate(list_of_numbers.begin(), list_of_numbers.end(), 0)) / list_of_numbers.size();
        std::cout << "\nThe mean of the numbers is: " << average << "\n" << std::endl;
    }
}

void handle_small(std::vector<int16_t> &list_of_numbers)
{
    if (list_of_numbers.empty()) {
        std::cout << "\nUnable to determine the smallest number - list is empty.\n" << std::endl;
    } else {
        int16_t min {*min_element(list_of_numbers.begin(), list_of_numbers.end())};
        std::cout << "\nThe smallest numbers is: " << min << "\n" << std::endl;
    }
}

void handle_large(std::vector<int16_t> &list_of_numbers)
{
    if (list_of_numbers.empty()) {
        std::cout << "\nUnable to determine the largest number - list is empty.\n" << std::endl;
    } else {
        int16_t max {*max_element(list_of_numbers.begin(), list_of_numbers.end())};
        std::cout << "\nThe largest numbers is: " << max << "\n" << std::endl;
    }
}

void handle_clear(std::vector<int16_t> &list_of_numbers)
{
    std::cout << "\nThe list is cleared!\n" << std::endl;
    list_of_numbers.clear();
}
void handle_wrong_choice()
{
    std::cout << "Wrong choice! Enter again!\n" << std::endl;
}


int main() {
    char user_choice;
    std::vector<int16_t> list_of_numbers;
    do {
        show_menu();
        user_choice = get_choice();
        switch (user_choice) {
            case 'P':
                handle_print(list_of_numbers);
                break;
            case 'A':
                handle_add(list_of_numbers);
                break;
            case 'M':
                handle_mean(list_of_numbers);
                break;
            case 'S':
                handle_small(list_of_numbers);
                break;
            case 'L':
                handle_large(list_of_numbers);
                break;
            case 'C':
                handle_clear(list_of_numbers);
                break;
            case 'F':
                handle_find(list_of_numbers);
                break;
            default:
                handle_wrong_choice();
        }
    } while(user_choice != 'Q');

    return 0;
}
