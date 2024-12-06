/************************************
 * Difference between while and do-while
 * while loop:
 * Condition is checked before the loop body executes.
 * If the condition is false initially, the loop body will not execute at all.
 * 
 * do-while loop:
 * Condition is checked after the loop body executes.
 * The loop body will always execute at least once, even if the condition is false.
 ************************************/

// Section 9
// Do-while
// Simple Menu Example
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    char selection {};
    do {
        cout << "\n---------------------" << endl;
        cout << "1. Do this" << endl;
        cout << "2. Do that" << endl;
        cout << "3. Do something else" << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;
        
        if (selection == '1')
            cout << "You chose 1 - doing this" << endl;
        else if (selection == '2') 
             cout << "You chose 2 - doing that" << endl;
        else if (selection == '3')
            cout << "You chose 3 - doing something else" << endl;   
        else if (selection == 'Q' || selection == 'q')
            cout << "Goodbye..." << endl;
        else 
            cout << "Unknown option -- try again..." << endl;
    
    } while ( selection != 'q' && selection != 'Q');
    
    cout << "============================================" << endl;
    /*******************************************************
     * Write your code in the provided area.
     * 
     * This code should use a do while loop to iterate over
     * the provided vector (vec) of characters looking 
     * for the first occurrence of a lowercase English vowel ('a','e','i','o','u').
     * 
     * If a vowel is found, you should display to cout:
     * 
     * "Vowel found: " followed by the vowel that was found.
     * 
     * If no vowel is found in the vector, then you should display to cout:
     * 
     * "No vowel was found"  
     * 
     * For example, below are several examples of vectors and what your output should be:
     * 
     * {'f','r','a','n','k'}    Vowel found: a
     * {'F','R','A','N','K'}    No vowel was found
     * {'h','e','l','l','o'}    Vowel found: e
     * {}                       No vowel was found
     * {'x','y','z','o'}        Vowel found: o
     * 
     *******************************************************/

    const vector<char> vec {'h','l','l', 'o'};  // Vowel found: e

    // My solution
    bool do_search = true;
    const vector<char> vowels {'a','e','i','o','u'};
    size_t index {0};
    do {
        if ( index >= vec.size() ) {
            cout << "No vowel was found" << endl;
            do_search = false;
        } else {
            for (char vowel: vowels) {
                if (vec.at(index) == vowel) {
                    do_search = false;
                    cout << "Vowel found: " << vec.at(index) << endl;
                }
            }
        index++;
        }
    } while ( do_search );

    cout << "========================================" << endl;

    // Tutor solution
    size_t i{0};
    bool vowel_found {false};
    if (!vec.empty()) {
        do {
            if (vec.at(i) == 'a' || vec.at(i) == 'e' || vec.at(i) == 'i' || vec.at(i) == 'o' || vec.at(i) == 'u') {
                vowel_found = true;
            } else {
                i++;
            }
        } while (!vowel_found && i < vec.size());
    if (vowel_found) {
        cout << "Vowel found: " << vec.at(i);
    } else {
        cout << "No vowel was found";
    }

    return 0;
}
