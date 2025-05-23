#include <iostream>
#include <cstdint>

using namespace std;

int main() {

    int score {};
    cout << "Enter your score on the exam (0-100): ";
    cin >> score;
    char letter_grade {};

    if (score >= 0 && score <= 100 ) {
        // Nested if blocks
        if (score >= 90)
            letter_grade = 'A';
        else if (score >= 80)
            letter_grade = 'B';
        else if (score >= 70)
            letter_grade = 'C';
        else if (score >= 60)
            letter_grade = 'D';
        else
            letter_grade = 'F';
        cout << "Your grade is: " << letter_grade << endl;
    } else {
        cout << "Sorry, " << score << " is not in range." << endl;
    }

    return 0;
}