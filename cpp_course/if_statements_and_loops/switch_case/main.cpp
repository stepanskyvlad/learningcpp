#include <iostream>
#include <cstdint>

using namespace std;

int main() {

    char letter_grade {};
    
    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;
    
    switch (letter_grade) {
        case 'a':
        case 'A':
            cout << "You need a 90 or above, study hard!" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80-89 for a B, go study!" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You need 70-79 for an average grade" << endl;
            break;
        case 'd':
        case 'D':
            cout << "Hmm, you should strive for a better grade. All you need is 60-69" << endl;
            break;
        case 'f':
        case 'F':
        {
            char confirm {};
            cout << "Are you sure (Y/N)? ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') 
                cout << "OK, I guess you didn't study..." << endl;
            else if (confirm == 'n' || confirm == 'N')
                cout << "Good- go study!" << endl;
            else 
                cout << "Illegal choice" << endl;
            break;
        }
           
        default:
            cout << "Sorry, not a valid grade" << endl;
    }
    
    /*******************************
     * Another example
     *******************************/
    cout << "=================Switch case using enum=====================" << endl; 

    enum Direction {
        left, right, up, down
    };

    Direction user_var {right};

    switch (user_var) {
        case left:
            cout << "Going left" << endl;
            break;
        case right:
            cout << "Going right" << endl;
            break;
        case up:
            cout << "Going up" << endl;
            break;
        case down:
            cout << "Going down" << endl;
            break;
        default:
            cout << "Unexpected value." << endl;
    }

    return 0;
}